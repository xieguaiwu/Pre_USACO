#!/usr/bin/env bash
# ═══════════════════════════════════════════════════════════════
#  USACO 一键判样例: 编译 → 跑 samples/ → 对拍 → (失败时)消毒器诊断
#
#  用法:
#    ../test.sh              # 在题目目录内, 自动找唯一 .cpp
#    ../test.sh 题目.cpp     # 显式指定 (可从仓库任意位置调用)
#
#  约定:
#    samples/ 下成对放样例:  1.in + 1.out  (或任意同名 x.in / x.out)
#    源码里有未注释的 freopen("X.in",...) → 自动切 USACO 文件模式
# ═══════════════════════════════════════════════════════════════
set -u
RED=$'\033[31m'; GRN=$'\033[32m'; YLW=$'\033[33m'; CYN=$'\033[36m'; NC=$'\033[0m'

die() { echo "${RED}❌ $*${NC}" >&2; exit 1; }

# ---------- 定位源文件 ----------
SRC="${1:-}"
if [[ -z "$SRC" ]]; then
    mapfile -t cands < <(ls -1 *.cpp 2>/dev/null)
    (( ${#cands[@]} == 1 )) || die "当前目录没有唯一的 .cpp (找到 ${#cands[@]} 个)。用法: test.sh 题目.cpp"
    SRC="${cands[0]}"
fi
[[ -f "$SRC" ]] || die "找不到源文件: $SRC"
DIR=$(cd "$(dirname "$SRC")" && pwd)      # 绝对路径, 防止 cd 后失效
SRCNAME=$(basename "$SRC")
cd "$DIR" || die "进不去 $DIR"

# ---------- 编译 ----------
BIN=".test_bin"
echo "${CYN}▶ 编译 $SRCNAME${NC}"
g++ -std=c++17 -O2 -Wall -Wextra -o "$BIN" "$SRCNAME" 2> .compile_warn
RC=$?
if (( RC )); then
    echo "${RED}── 编译失败 ──${NC}"; cat .compile_warn; rm -f .compile_warn; exit 1
fi
if [[ -s .compile_warn ]]; then
    echo "${YLW}⚠️ 编译警告 (常见 bug 预警, 建议看一眼):${NC}"; cat .compile_warn
fi
rm -f .compile_warn

# ---------- 判定模式 ----------
PROB=$(grep -E 'freopen\(' "$SRCNAME" | grep -vE '^\s*//' | grep -oE '"[^"]+\.in"' | head -1 | tr -d '"' | sed 's/\.in$//')
if [[ -n "$PROB" ]]; then
    echo "${CYN}▶ 模式: USACO 文件模式 ($PROB.in / $PROB.out)${NC}"
else
    echo "${CYN}▶ 模式: stdin/stdout (洛谷)${NC}"
fi

[[ -d samples ]] || die "没有 samples/ 目录。建一个, 放入 1.in + 1.out 再跑"
mapfile -t ins < <(ls -1 samples/*.in 2>/dev/null)
(( ${#ins[@]} > 0 )) || die "samples/ 里没有 .in 文件"

# ---------- 跑样例 ----------
pass=0; fail=0; first_fail_in=""
for s_in in "${ins[@]}"; do
    name=$(basename "$s_in" .in)
    s_out="samples/$name.out"
    [[ -f "$s_out" ]] || { echo "${YLW}⚠️ 缺 $s_out, 跳过 $name${NC}"; continue; }

    if [[ -n "$PROB" ]]; then
        cp "$s_in" "$PROB.in"
        timeout 5s "./$BIN" > /dev/null 2> .run_err; rc=$?
        actual="$PROB.out"
    else
        timeout 5s "./$BIN" < "$s_in" > .actual_out 2> .run_err; rc=$?
        actual=".actual_out"
    fi

    if (( rc == 124 )); then
        echo "${RED}❌ [$name] 超时 (>5s)${NC}"; ((fail++)); [[ -z $first_fail_in ]] && first_fail_in="$name"; continue
    elif (( rc != 0 )); then
        echo "${RED}❌ [$name] 运行时错误 (rc=$rc):${NC}"; head -5 .run_err; ((fail++)); [[ -z $first_fail_in ]] && first_fail_in="$name"; continue
    fi

    if diff -q <(sed -e 's/[[:space:]]*$//' "$actual") <(sed -e 's/[[:space:]]*$//' "$s_out") > /dev/null; then
        echo "${GRN}✅ [$name] 通过${NC}"; ((pass++))
    else
        echo "${RED}❌ [$name] 答案不符${NC}"
        echo "  ${YLW}── 期望 ──${NC}"; sed 's/^/  │ /' "$s_out" | head -8
        echo "  ${YLW}── 实际 ──${NC}"; sed 's/^/  │ /' "$actual" | head -8
        echo "  (完整 diff: diff samples/$name.out $actual)"
        ((fail++)); [[ -z $first_fail_in ]] && first_fail_in="$name"
    fi
done
rm -f .actual_out .run_err

# ---------- 失败 → 消毒器复跑 (抓越界/未初始化) ----------
if (( fail > 0 )) && [[ -n "$first_fail_in" ]]; then
    echo "${CYN}▶ 用 AddressSanitizer 复跑失败样例 (抓数组越界/未初始化)…${NC}"
    if g++ -std=c++17 -g -fsanitize=address,undefined -o "${BIN}_dbg" "$SRCNAME" 2>/dev/null; then
        if [[ -n "$PROB" ]]; then
            cp "samples/$first_fail_in.in" "$PROB.in"
            timeout 10s "./${BIN}_dbg" > /dev/null 2> .san_err
        else
            timeout 10s "./${BIN}_dbg" < "samples/$first_fail_in.in" > /dev/null 2> .san_err
        fi
        if [[ -s .san_err ]]; then echo "${YLW}⚠️ 消毒器报告:${NC}"; head -12 .san_err
        else echo "  消毒器无新发现 → 大概率是纯逻辑错"; fi
        rm -f .san_err "${BIN}_dbg"
    else
        echo "  (本机无 libasan, 跳过)"
    fi
fi

echo "────────────────────"
if (( fail == 0 )); then
    echo "${GRN}🎉 $pass/$pass 全过 — 可以 commit 了${NC}"
    rm -f "$BIN"; exit 0
else
    echo "${RED}💥 $pass 过 / $fail 挂 — 修完再 commit${NC}"; exit 1
fi
