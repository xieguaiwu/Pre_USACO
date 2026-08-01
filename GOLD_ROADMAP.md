# USACO Gold 备战路线 · 洛谷题单（2026-08-01 核验版）

> 全部题号已于 2026-08-01 通过 web 检索逐题核验（以 luogu.com.cn 页面标题为准）。
> 两处纠错：P6119 ≠ Cow Poetry G（实为 Why Did the Cow Cross the Road II G），Cow Poetry G = **P5196**；
> P9127 官方标题为 **Equal** Sum Subarrays G。

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

## 四、执行建议

1. **先收尾**：0717/market_day.cpp（N 未读入即用）、0717/teacher.cpp 补完，再开始阶段 0。
2. **节奏**：每天 1-2 题，先 AC 模板题再 AC 真题；每阶段结束做一次自我总结（错误类型、卡点）。
3. **参考题单导航**（洛谷内）：能力全面提升综合题单 training/9391；《算法竞赛进阶指南》题单 training/400（DP 部分 83815、图论部分 81272）；USACO 经典题目 training/7185。
4. **时间线**：阶段 0-3 ≈ 2.5-3.5 个月 → 12 月/1 月场稳 Silver → 阶段 4 真题 + 2-3 月场冲 Gold。
5. **补弱原则**：Gold 考场 = 4 题中通常 ≥2 题 DP，DP 是绝对重心；图论次之。数据结构（线段树/树状数组）是 DP 优化的武器，别只背模板。
