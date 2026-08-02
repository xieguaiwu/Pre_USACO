# USACO Gold 备战路线 · 洛谷题单（2026-08-02 更新：含赛制研究）

> 全部题号已于 2026-08-01 通过 web 检索逐题核验（以 luogu.com.cn 页面标题为准）。
> 两处纠错：P6119 ≠ Cow Poetry G（实为 Why Did the Cow Cross the Road II G），Cow Poetry G = **P5196**；
> P9127 官方标题为 **Equal** Sum Subarrays G。

## 〇、赛制研究（2026-08-02 核实，针对"首次参赛升 Gold"）

### 关键结论：首场直接升 Gold 不可行，最快 = 同一赛季两场（12月 Bronze→Silver 当场，1月 Silver→Gold 当场）

**2025-2026 赛季起的新规（多来源交叉确认，含 usaco.org.cn 官方中文站）：**

| 项目 | 规则 |
|---|---|
| 起点 | 所有新选手从 Bronze 开始，**无跳级机制**（不能首场直接考 Gold） |
| 晋级上限 | **每场最多升一级**（旧规则可当场连升铜→银→金，新规已取消） |
| 当场升级 | 满分（1000 分）→ 当场自动升入下一级，可点击开始下一级比赛（**全新 4 小时时钟**） |
| 放榜升级 | 非满分 → 赛后约 1 周放榜，按分数线晋级（通常 700-800 分，历史多为 750；2026 第三场 Silver→Gold 线为 700） |
| 计分 | 每场 3 题，总分 1000，每题约 333 分 |
| 晋级永久 | 升级终身有效、跨赛季不降级 |
| AI/VPN | 严禁生成式 AI（ChatGPT/Copilot 等）与远程协作；美国选手禁用 VPN。违者封号+成绩作废 |
| 认证窗口 | Gold/Platinum 组须美东周六 12:00 ET 开赛（北京周日 00:00-00:15）成绩才"认证"；Bronze/Silver 组不受限 |

**2026-2027 赛季预计（官方时间表通常秋季公布）：** 第一场 2026年12月12-15日（4天窗口任选连续4小时）、第二场 2027年1月末/2月初、第三场 2027年2月中下旬、US Open 2027年3月底（机构预测，以官方公布为准）。

**对计划的影响：**
1. 第一场（12月）目标 = **Bronze 满分 1000**（不是 750）：满分当场升 Silver 且**白赚 4 小时当场打 Silver 组**（正式环境实战+摸底，为第二场铺路）；750 只能等放榜升 Silver，浪费当场机会。
2. 第二场（1月末/2月初）目标 = **Silver 700+** → 当场升 Gold。
3. 所以"第一赛季升 Gold"= 两场，训练重心 = 12月前 Bronze 满分特训 + 当场 Silver 实战；12月-1月补 Silver 缺口。
4. 中国选手升 Gold 无认证时间限制（认证主要约束 Gold/Platinum 组参赛与训练营选拔）；到 Gold 后若想冲 Platinum 再关注认证细节。
5. 比赛期间严禁 AI 辅助（本 agent 只能用于赛前训练，不能用于比赛现场）。

### 修正后的时间线

| 时间 | 目标 | 内容 |
|---|---|---|
| 现在-10月中 | Bronze 满分特训 | BRONZE_PRACTICE.md 全 80 题 + GOLD_ROADMAP 阶段 0（二分/前缀和/贪心/单调栈队列）| 
| 10月中-12月初 | Silver 预备 | 阶段 1 DP 前半 + 阶段 2 图论入门 + 阶段 3 数据结构前半 |
| **12月第一场** | **Bronze 1000 → 当场 Silver** | 当场 4 小时打 Silver 组（摸底，能拿多少拿多少） |
| 12月中-1月末 | Silver 冲刺 | Silver 真题限时模拟 + 补弱点 |
| **1月末/2月初第二场** | **Silver 700+ → 当场 Gold** ✅ | 达成"第一赛季升 Gold" |
| 2月第三场 / 3月 US Open | Gold 组实战 | Gold 真题（阶段 4 列表）热身，冲 Platinum 线 750（认证细节以官方为准） |


## 一、当前进度盘点（0717 / 0720 / 0726）

| 目录 | 题目 | 内容 | 水平 |
|---|---|---|---|
| 0717 | bakery.cpp | 统计奶牛喜好计数取 max（USACO Dec 2024 Bronze 类） | Bronze |
| 0717 | social_dis.cpp | 奶牛安置最大最小间距（Social Distancing I 思路） | Bronze/Silver 边界 |
| 0717 | Tractor.cpp | 区间重叠长度 | Bronze |
| 0717 | market_day.cpp | **未完成**：N 未读入就使用，代码有 bug | 需收尾 |
| 0717 | teacher.cpp | **未完成**：区间交模板半成品 | 需收尾 |
| 0720 | CircularFeedStation.cpp | 环形送料最小总成本，O(N²) 枚举起点 | Bronze（可优化为 O(N) 破环成链+滑动窗口） |
| 0720 | LeaderboardLights.cpp | 求最大值出现次数 + 循环轮转 | Bronze |
| 0726 | BalancedBreedBlock.cpp / _opt.cpp | 三品种平衡区间（计数差值 ≤1），O(N²) 滑动窗口 | Bronze/Silver 边界 |
| 0726 | TankLog.cpp | 多水箱倒水模拟 | Bronze |
| basics/greedy | 背包 / 打水 / 合并果子 | 贪心入门 | Bronze |
| basics/pointer_problems | 30 道指针练习 | C++ 基本功 | — |

**结论**：目前稳定在 Bronze 中上，个别题摸到 Silver 边缘（二分思想、滑动窗口计数）。
按 2026 年起"每场最多升一级"的规则，合理路径：**先稳过 Silver（12 月/1 月场），再冲 Gold（2-3 月场）**。

## 二、差距分析：Bronze → Gold 需要补的能力

Gold 官方高频考点（USACO Guide / 近年真题统计）：

1. **DP（第一瓶颈）**：线性 DP、背包（0/1、完全）、LIS/LCS、区间 DP、树形 DP、状压 DP、DAG 上 DP
2. **图论**：堆优化 Dijkstra、0-1 BFS、次短路、Floyd、MST（Kruskal/Prim）、拓扑排序、并查集
3. **数据结构**：树状数组、线段树（含懒标记）、单调队列/单调栈、堆、ST 表、字符串哈希
4. **数学**：快速幂、矩阵快速幂、素数筛、逆元、组合计数
5. **基础（Silver 必修，当前欠缺）**：二分答案、前缀和/差分、区间贪心、DFS/BFS

## 三、洛谷题单（按阶段，★=先做）

### 阶段 0：收尾 + Silver 过渡（约 2 周）

| 题号 | 标题 | 考点 |
|---|---|---|
| P8218 ★ | 【深进1.例1】求区间和 | 前缀和模板 |
| P3397 ★ | 地毯 | 二维差分 |
| P1223 ★ | 排队接水 | 贪心 |
| P1803 ★ | 凌乱的yyy / 线段覆盖 | 区间贪心 |
| P2440 ★ | 木材加工 | 二分答案 |
| P1873 ★ | 砍树 | 二分答案 |
| P1824 | [USACO05FEB] 进击的奶牛 Aggressive Cows G | 二分答案（USACO G 原题，难度入门） |
| P1605 | 迷宫 | DFS |
| P1443 | 马的遍历 | BFS |
| P5788 ★ | 【模板】单调栈 | 单调栈 |
| P1886 ★ | 【模板】单调队列/滑动窗口 | 单调队列 |

### 阶段 1：DP 核心（约 3 周，Gold 第一瓶颈）

| 题号 | 标题 | 考点 |
|---|---|---|
| P1216 ★ | 数字三角形 | 线性 DP 入门 |
| P1002 ★ | 过河卒 | 网格 DP |
| P1048 ★ | 采药 | 0/1 背包 |
| P1060 ★ | 开心的金明 | 0/1 背包 |
| P1616 ★ | 疯狂的采药 | 完全背包 |
| P1020 ★ | 导弹拦截 | LIS + 贪心二分 |
| P1439 ★ | 【模板】最长公共子序列 | LCS→LIS 转化 |
| P1775 ★ | 石子合并（弱化版） | 区间 DP |
| P1880 | 石子合并 | 区间 DP（环形） |
| P1063 | 能量项链 | 区间 DP（环形） |
| P1040 | 加分二叉树 | 区间 DP（输出方案） |
| P1352 ★ | 没有上司的舞会 | 树形 DP |
| P1122 | 最大子树和 | 树形 DP |
| P2015 | 二叉苹果树 | 树上背包 |
| P2014 | 选课 | 树上背包 |
| P1433 ★ | 吃奶酪 | 状压 DP |
| P1896 | 互不侵犯 | 状压 DP |
| P1113 ★ | 杂务 | 拓扑 + DP |
| P4017 | 最大食物链计数 | 拓扑计数 |

### 阶段 2：图论核心（约 2-3 周）

| 题号 | 标题 | 考点 |
|---|---|---|
| P3367 ★ | 【模板】并查集 | DSU |
| P1536 ★ | 村村通 | DSU 连通分量 |
| P1197 | 星球大战 | 离线 DSU（倒序加边） |
| P3371 ★ | 单源最短路（弱化版） | Dijkstra/SPFA |
| P4779 ★ | 单源最短路（标准版） | 堆优化 Dijkstra |
| P1144 ★ | 最短路计数 | 最短路计数 |
| P1821 | [USACO07FEB] Cow Party S | 双向 Dijkstra |
| P2865 ★ | [USACO06NOV] Roadblocks G | **次短路（Gold 真题）** |
| P2888 | [USACO07NOV] Cow Hurdles S | Floyd |
| P2910 | [USACO08OPEN] Clear And Present Danger S | Floyd |
| P3366 ★ | 【模板】最小生成树 | Kruskal/Prim |
| P1546 ★ | [USACO3.1] 最短网络 Agri-Net | MST |
| P2330 | 繁忙的都市 | MST 贪心 |
| P1991 | 无线通讯网 | MST（第 k 大边） |
| P1983 | 车站分级 | 拓扑 + 差分思想（选做） |
| P1948 | [USACO08JAN] Telephone Lines S | 二分答案 + 0-1 BFS/Dijkstra 变体 |

### 阶段 3：数据结构 & 数学（约 2-3 周）

| 题号 | 标题 | 考点 |
|---|---|---|
| P3374 ★ | 【模板】树状数组 1 | 单点改区间查 |
| P3368 ★ | 【模板】树状数组 2 | 区间改单点查 |
| P1908 ★ | 逆序对 | 树状数组/归并 |
| P3372 ★ | 【模板】线段树 1 | 区间和 |
| P3373 | 【模板】线段树 2 | 懒标记 |
| P3378 ★ | 【模板】堆 | 堆 |
| P1090 ★ | 合并果子 | 贪心 + 堆 |
| P3370 ★ | 【模板】字符串哈希 | 哈希 |
| P1226 ★ | 【模板】快速幂 | 快速幂 |
| P3390 | 【模板】矩阵快速幂 | 矩阵快速幂 |
| P3383 | 【模板】线性筛素数 | 素数筛 |
| P3811 | 【模板】模意义下的乘法逆元 | 逆元 |
| P1029 | 最大公约数和最小公倍数问题 | gcd/lcm |
| P2880 | [USACO07JAN] Balanced Lineup G | ST 表/RMQ（Gold 真题） |

### 阶段 4：USACO Gold 真题实战（考前 4-6 周，按难度递进）

| 题号 | 标题 | 考点 |
|---|---|---|
| P1824 | Aggressive Cows G（已列阶段 0） | 二分 |
| P2865 | Roadblocks G（已列阶段 2） | 次短路 |
| P1879 ★ | [USACO06NOV] Corn Fields G | 状压 DP |
| P3092 ★ | [USACO13NOV] No Change G | 状压 DP |
| P5196 ★ | [USACO19JAN] Cow Poetry G | 组合计数 DP |
| P5837 | [USACO19DEC] Milk Pumping G | 最短路变体 |
| P6146 | [USACO20FEB] Help Yourself G | 排序 + DP |
| P6005 | [USACO20JAN] Time is Mooney G | 图上 DP |
| P6006 | [USACO20JAN] Farmer John Solves 3SUM G | 区间 DP/思维 |
| P6007 | [USACO20JAN] Springboards G | 偏序 + DP/树状数组 |
| P9128 | [USACO23FEB] Fertilizing Pastures G | 树形 DP |
| P9129 | [USACO23FEB] Piling Papers G | DP |
| P9127 | [USACO23FEB] Equal Sum Subarrays G | 前缀和 + 思维 |
| P6279 | [USACO20OPEN] Favorite Colors G | DSU（较难） |
| P6098 | [USACO19FEB] Cow Land G | 树链剖分（选做） |
| P14980 | [USACO26JAN] COW Traversals G | 最新赛季（数据结构） |

## 四、执行建议（已按 2026-08-02 赛制研究修订）

1. **先收尾**：0717/market_day.cpp（N 未读入即用）、0717/teacher.cpp 补完，再开始刷题。
2. **节奏**：8月-10月 每天 1-2 题（BRONZE_PRACTICE.md C/A 组打底 → B/D 组查漏 → E 组限时模拟），10月-12月转 GOLD_ROADMAP 阶段 0-2；每阶段做自我总结（错误类型、卡点）。
3. **第一场（12月）策略 = Bronze 满分**：3 题全对（1000 分）才能当场升 Silver + 白赚当场 4 小时打 Silver 组；750 只能放榜升级。E 组近年真题要考前 2-3 周限时 4 小时模拟（每题 333 分制）。
4. **第二场（1月末/2月初）策略 = Silver 700+**：当场升 Gold。12月-1月集中 Silver 真题限时模拟（可另挖 2022-2025 Silver 真题洛谷题号）。
5. **参考题单导航**（洛谷内）：能力全面提升综合题单 training/9391；《算法竞赛进阶指南》题单 training/400（DP 部分 83815、图论部分 81272）；USACO 经典题目 training/7185。
6. **比赛纪律**：正式比赛严禁生成式 AI/远程协作（违者封号）；本 agent 只用于赛前训练与复盘。
7. **补弱原则**：Gold 考场通常 ≥2 题 DP，DP 是绝对重心；图论次之。数据结构（线段树/树状数组）是 DP 优化的武器，别只背模板。
