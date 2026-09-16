# USACO Silver & Gold 完整知识点清单

> 来源：USACO Guide (usaco.guide)、USACO 官方 (usaco.org)、barryhan.net 交叉整理
> 更新时间：2026-09-16

---

## 目录

- [🥈 Silver（白银）](#silver白银)
  - [1. 图遍历 BFS & DFS](#1-图遍历-bfs--dfs)
  - [2. 网格泛洪填充 Flood Fill](#2-网格泛洪填充-flood-fill)
  - [3. 二分答案 Binary Search on the Answer](#3-二分答案-binary-search-on-the-answer)
  - [4. 双指针与滑动窗口 Two Pointers & Sliding Window](#4-双指针与滑动窗口-two-pointers--sliding-window)
  - [5. 一维 & 二维前缀和 Prefix Sums](#5-一维--二维前缀和-prefix-sums)
  - [6. 排序 + 特例 Sorting + Ad-hoc](#6-排序--特例-sorting--ad-hoc)
  - [7. 单调栈与单调队列 Monotonic Stack & Deque](#7-单调栈与单调队列-monotonic-stack--deque)
  - [8. 有序容器 Set / Map / Multiset](#8-有序容器-set--map--multiset)
  - [Silver 补充：贪心算法](#silver-补充贪心算法)
- [🥇 Gold（黄金）](#gold黄金)
  - [1. 动态规划 Dynamic Programming](#1-动态规划-dynamic-programming)
  - [2. 最短路径 Shortest Paths](#2-最短路径-shortest-paths)
  - [3. 并查集 Union-Find / DSU](#3-并查集-union-find--dsu)
  - [4. 拓扑排序 & DAG 上的 DP](#4-拓扑排序--dag-上的-dp)
  - [5. 线段树与树状数组 Segment / Fenwick Tree](#5-线段树与树状数组-segment--fenwick-tree)
  - [6. 倍增法 / 最近公共祖先 Binary Lifting / LCA](#6-倍增法--最近公共祖先-binary-lifting--lca)
  - [7. 数论与模运算 Number Theory & Modular Arithmetic](#7-数论与模运算-number-theory--modular-arithmetic)
  - [8. 字符串算法 String Algorithms](#8-字符串算法-string-algorithms)
- [📊 复杂度速查表](#复杂度速查表)
- [📚 推荐学习资源](#推荐学习资源)

---

## 🥈 Silver（白银）

> **定位**：算法真正起点。约束 ~10⁵，O(n²) 暴力会 TLE，每题至少需要一种 O(n log n) 思路。
> **前提**：已熟练掌握 Bronze 所有内容（暴力枚举、模拟、基础贪心、一维前缀和、基础递归）。

---

### 1. 图遍历 BFS & DFS

**核心内容**：
- **BFS（广度优先搜索）**：队列实现，用于无权图最短路径
- **DFS（深度优先搜索）**：栈或递归实现，用于连通性判断

**具体考点**：
- 连通分量计数（Connected Components）
- Flood Fill 的基础
- 无权图最短路径（BFS）
- 环检测（DFS 判回边）
- 二分图判定（染色法 BFS/DFS）

**易错点**：
- 递归 DFS 在 n=10⁵ 时可能栈溢出 → 改用迭代或手动增大栈（`std::thread` / `ios::sync_with_stdio(false)` + 手动栈）

**经典题型**：
- 数岛屿数量
- 找最大连通区域
- "腐烂的橘子"（多源 BFS）
- 迷宫最短步数

---

### 2. 网格泛洪填充 Flood Fill

**核心内容**：
- 2D 网格上的 BFS/DFS 特例
- 四连通 / 八连通方向遍历

**具体考点**：
- 统计连通区域数量
- 找最大连通区域面积
- 区域周长计算
- 填充/染色操作

**说明**：几乎每场 Silver 必考一题 Flood Fill。

**经典题型**：
- 数岛屿（Number of Islands）
- 最大连通区域
- 农田分组（USACO 经典题）

---

### 3. 二分答案 Binary Search on the Answer

**核心内容**：
- 当答案具有**单调性**时，对答案 X 进行二分搜索
- 将原问题转化为判定问题："值 ≥ X 是否可行？"

**具体考点**：
- 整数二分（求最小可行值 / 最大可行值）
- 实数二分（精度控制）
- 二分答案 + 贪心验证
- 二分答案 + BFS/DFS 验证

**经典模板**：
```
while (l < r) {
    mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
}
```

**经典题型**：
- "最小化最大值"类问题
- Aggressive Cows（愤怒的牛）
- 最小化最大子数组和
- 最小化完成时间

---

### 4. 双指针与滑动窗口 Two Pointers & Sliding Window

**核心内容**：
- 维护窗口 [l, r]，扩展 r 时 l 只前不退（单调性）
- 适用于子数组/子串满足某条件的问题

**具体考点**：
- 最长满足条件的子数组
- 和 ≤ k 的子数组个数
- 恰好 k 个不同元素的子数组
- 最小覆盖子串

**前提条件**：扩展 r 时，条件单调变化（即 l 不需要回退）

**经典题型**：
- 最长无重复字符子串
- 和 ≥ target 的最短子数组
- 乘积小于 k 的子数组个数

---

### 5. 一维 & 二维前缀和 Prefix Sums

**核心内容**：
- **1D 前缀和**：`pref[i] = a[0] + a[1] + ... + a[i-1]`，区间和 O(1) 查询
- **2D 前缀和**：`pref[i][j]` = 矩形 (0,0) 到 (i-1,j-1) 的和，容斥原理 O(1) 查询

**具体考点**：
- 子数组和等于 s 的个数
- 最大子数组和 ≤ k
- 2D 子矩阵和查询
- 差分数组（区间加 + 单点查询的逆操作）

**经典题型**：
- 和为 K 的子数组
- 最大和矩形 ≤ k
- 矩阵区域和检索

---

### 6. 排序 + 特例 Sorting + Ad-hoc

**核心内容**：
- 按巧妙关键字排序后，线性扫描解决
- 大多数 Silver 贪心题的本质

**具体考点**：
- 最早截止时间优先（Earliest Deadline First）
- 按开始/结束时间排序处理区间
- 自定义比较器排序
- 分数背包（按价值密度排序）

**经典题型**：
- 最大不重叠区间数
- 最小会议室数量
- 任务调度最大收益

---

### 7. 单调栈与单调队列 Monotonic Stack & Deque

**核心内容**：
- **单调栈**：维护递增/递减栈，用于"下一个更大/更小元素"
- **单调双端队列**：维护滑动窗口最值

**具体考点**：
- 下一个更大元素（Next Greater Element）
- 直方图中最大矩形面积
- 滑动窗口最大值 / 最小值
- 接雨水问题

**经典题型**：
- Largest Rectangle in Histogram
- Sliding Window Maximum
- 接雨水（Trapping Rain Water）
- 股票价格跨度

---

### 8. 有序容器 Set / Map / Multiset

**核心内容**：
- `std::set`：有序集合，支持 O(log n) 插入 + lower_bound/upper_bound
- `std::map`：有序键值对，按键排序
- `std::multiset`：可重复的有序集合
- `std::unordered_set/map`：哈希实现，O(1) 平均

**具体考点**：
- 动态第 k 小元素（multiset 维护）
- 扫描过程中统计 ≤ x 的元素个数
- 区间内元素个数（order_of_key，需 PBDS）
- 去重 + 排序

**经典题型**：
- 动态中位数
- 逆序对计数（配合 BIT）
- 数据流中的第 k 大元素

---

### Silver 补充：贪心算法

**核心思想**：
- 局部最优 → 全局最优
- 必须证明贪心正确性（交换论证、归纳法）

**常见贪心策略**：
- 按结束时间排序选区间
- 按开始时间排序 + 优先队列
- 哈夫曼编码类（每次取最小的两个）
- 排序后配对

---

## 🥇 Gold（黄金）

> **定位**：真正的竞赛编程。需要**非平凡思路 + 干净实现**，难度跳升最大的一级。
> **前提**：已熟练掌握 Silver 全部内容。Gold 题默认你会 BFS/DFS、前缀和、二分、排序。

---

### 1. 动态规划 Dynamic Programming

**核心心法**：先精确定义状态，转移自然写出。

#### 1.1 1D DP
- 线性序列上的 DP
- 状态：`dp[i]` = 前 i 个元素的最优值
- 经典：最长递增子序列（LIS）、最大子数组和、爬楼梯

#### 1.2 2D DP
- 网格上的 DP
- 状态：`dp[i][j]` = 到 (i,j) 的最优值
- 经典：网格路径最小和、编辑距离、最长公共子序列（LCS）

#### 1.3 区间 DP
- 状态：`dp[l][r]` = 区间 [l,r] 的最优值
- 转移：枚举分割点 k
- 经典：矩阵链乘法、最优二叉搜索树、合并石子

#### 1.4 树形 DP
- 状态：`dp[u][0/1]` = 以 u 为根的子树的最优值
- 经典：树的最大独立集、树的最小点覆盖、树的直径

#### 1.5 状压 DP（Bitmask DP）
- 状态：`dp[mask]` = 已选集合为 mask 时的最优值
- 适用：n ≤ 20 的排列/分配问题
- 经典：旅行商问题（TSP）、任务分配、覆盖问题

#### 1.6 DP 常用技巧
- 前缀和优化 DP
- 滚动数组降空间
- 初始状态设定技巧
- 答案回溯（记录决策）

---

### 2. 最短路径 Shortest Paths

#### 2.1 Dijkstra 算法
- 适用：非负权图
- 实现：优先队列（二叉堆）O((V+E) log V)
- 变种：多源 Dijkstra、记录路径

#### 2.2 Bellman-Ford 算法
- 适用：含负权边（无负环）
- 实现：松弛 V-1 轮 O(VE)
- 应用：检测负环

#### 2.3 0-1 BFS
- 适用：边权 ∈ {0, 1}
- 实现：双端队列（边权 0 放队首，边权 1 放队尾）O(V+E)

#### 2.4 Floyd-Warshall 算法
- 适用：全源最短路径，n ≤ 400
- 实现：三重循环 O(V³)
- 应用：传递闭包、最小环

#### 2.5 SPFA（Shortest Path Faster Algorithm）
- Bellman-Ford 的队列优化
- 平均较快，最坏 O(VE)，可被卡

**经典题型**：
- 最短路径 + 一条边权重减半
- 多源最短路径
- 分层图最短路
- 受限最短路径

---

### 3. 并查集 Union-Find / DSU

**核心操作**：
- `find(x)`：查找 x 的根（路径压缩）
- `union(x, y)`：合并两个集合（按秩/大小合并）

**时间复杂度**：均摊 O(α(n)) ≈ O(1)（α 为反阿克曼函数）

**具体考点**：
- Kruskal 最小生成树（MST）
- 离线连通性查询
- 可回滚并查集（Rollback DSU）
- 带权并查集（维护到根的距离）
- 扩展域并查集（种类并查集）

**经典题型**：
- Kruskal MST
- Closing the Farm（离线删点转逆向加边）
- Mootube（带权连通性）
- 食物链（种类并查集）

---

### 4. 拓扑排序 & DAG 上的 DP

#### 4.1 拓扑排序
- **Kahn 算法**（BFS 式）：入度为 0 的节点入队
- **DFS 式**：后序遍历的逆序
- 应用：判断是否有环、任务调度

#### 4.2 DAG 上的 DP
- 按拓扑序进行 DP
- 状态：`dp[u]` = 从起点到 u 的最优值
- 经典：DAG 最长路径、关键路径

**经典题型**：
- 最长路径 in DAG
- 带前置条件的任务调度
- 课程表 III（最多能修多少门课）

---

### 5. 线段树与树状数组 Segment / Fenwick Tree

#### 5.1 树状数组（Fenwick Tree / BIT）
- 操作：单点更新 + 前缀和查询 O(log n)
- 扩展：区间加 + 单点查、区间加 + 区间查（差分 BIT）
- 代码短、常数小

#### 5.2 线段树（Segment Tree）
- 操作：单点/区间更新 + 区间查询 O(log n)
- 支持：区间和、区间最值、区间 GCD 等
- **懒惰传播**（Lazy Propagation）：区间更新 O(log n)

#### 5.3 可持久化线段树（Platinum 前置）
- 每个版本共享未修改的节点
- 应用：区间第 k 小

**经典题型**：
- 区间和 + 单点更新
- 区间最值 + 区间赋值/加法
- 逆序对计数
- 区间内不同数字个数

---

### 6. 倍增法 / 最近公共祖先 Binary Lifting / LCA

**核心内容**：
- 预计算 `up[u][k]` = 节点 u 的 2^k 级祖先
- 预处理 O(n log n)，查询 O(log n)

**具体考点**：
- LCA（最近公共祖先）
- 第 k 个祖先查询
- 树上路径最值查询
- 树上距离计算

**经典题型**：
- LCA 查询
- 树上路径最大边权
- 跳跃指针问题

---

### 7. 数论与模运算 Number Theory & Modular Arithmetic

#### 7.1 基础
- GCD / LCM（欧几里得算法）
- 扩展欧几里得算法（求 ax + by = gcd 的解）
- 质数判定、质因数分解

#### 7.2 筛法
- 埃拉托斯特尼筛法 O(n log log n)
- 欧拉筛（线性筛）O(n)

#### 7.3 模运算
- 模幂运算（快速幂）O(log n)
- 模逆元：费马小定理（模为质数）/ 扩展欧几里得
- 组合数取模：预处理阶乘 + 逆元

#### 7.4 组合数学
- 排列组合公式
- 容斥原理
- 鸽巢原理

**经典题型**：
- 路径计数 mod 10⁹+7
- nCk mod p
- 模意义下的线性方程

---

### 8. 字符串算法 String Algorithms

#### 8.1 KMP 算法
- 前缀函数（failure function）
- 模式匹配 O(n + m)
- 应用：找所有匹配位置、周期串判定

#### 8.2 Z-function
- Z[i] = s 与 s[i:] 的最长公共前缀
- 线性 O(n)
- 应用：模式匹配、字符串周期

#### 8.3 字符串哈希（Polynomial Hashing）
- 预处理 O(n)，子串哈希 O(1)
- 双哈希避免冲突
- 应用：子串相等判定、最长重复子串

**经典题型**：
- 最长重复子串
- 周期串判定
- 字符串匹配
- 最长公共前缀

---

## 📊 复杂度速查表

| n 上限 | 2 秒内可行 | 典型算法 |
|---|---|---|
| 10 | O(n!) ≈ 360 万 | 排列枚举 |
| 20 | O(2ⁿ) ≈ 100 万 | 状压 DP、子集枚举 |
| 100 | O(n³) ≈ 100 万 | Floyd-Warshall、n³ DP |
| 2,000 | O(n²) ≈ 400 万 | 成对 DP |
| 10⁵ | O(n log n) ≈ 1000 万 | 排序、线段树、Dijkstra |
| 10⁶ | O(n) 或 O(n log log n) | 线性扫描、筛法 |
| 10⁹ | O(log n) 或 O(√n) | 数学闭式、二分搜索 |

> USACO 判题 C++ 约 2 秒。安全目标：10⁸ 次简单操作以内。

---

## 📚 推荐学习资源

| 资源 | 说明 |
|---|---|
| [USACO Guide](https://usaco.guide) | 最权威的免费学习路线，含精选题目 |
| [USACO 官方题库](https://usaco.org/index.php?page=training) | 历年真题 + 官方题解 |
| [CSES Problem Set](https://cses.fi/problemset/) | 按主题分类的高质量题单 |
| [Codeforces EDU](https://codeforces.com/edu/courses) | 互动式算法教程 |
| [CP-Algorithms](https://cp-algorithms.com) | 算法参考手册 |
| [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf) | Antti Laaksonen 免费教材 |

---

## 🎯 晋级路径总结

| 级别 | 核心新增 | 关键能力 |
|---|---|---|
| **Bronze** | 暴力枚举、模拟、贪心、前缀和 | 读题 + 边界处理 |
| **Silver** | BFS/DFS、二分、双指针、单调结构、有序容器 | 标准算法工具 |
| **Gold** | DP、最短路、DSU、拓扑、线段树、LCA、数论、字符串 | 非平凡思路 + 干净实现 |
| **Platinum** | 重型 DS、树分解、网络流、DP 优化、SCC、后缀结构、FFT | 一个巧妙观察 + 重型结构 |

> **学习建议**（来自 USACO Guide）：每个 topic 做 5–10 道题再往下走。Gold 题默认你已经掌握 Silver，跳过 Silver 直接打 Gold 会浪费数周在一道其实需要前缀和的题上。
