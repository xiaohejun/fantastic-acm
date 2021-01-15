/*
 * @lc app=leetcode.cn id=947 lang=c
 *
 * [947] 移除最多的同行或同列石头
 *
 * https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/description/
 *
 * algorithms
 * Medium (53.98%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 28.6K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]'
 *
 * n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。
 * 
 * 如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头。
 * 
 * 给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置，返回 可以移除的石子
 * 的最大数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * 输出：5
 * 解释：一种移除 5 块石头的方法如下所示：
 * 1. 移除石头 [2,2] ，因为它和 [2,1] 同行。
 * 2. 移除石头 [2,1] ，因为它和 [0,1] 同列。
 * 3. 移除石头 [1,2] ，因为它和 [1,0] 同行。
 * 4. 移除石头 [1,0] ，因为它和 [0,0] 同列。
 * 5. 移除石头 [0,1] ，因为它和 [0,0] 同行。
 * 石头 [0,0] 不能移除，因为它没有与另一块石头同行/列。
 * 
 * 示例 2：
 * 
 * 
 * 输入：stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * 输出：3
 * 解释：一种移除 3 块石头的方法如下所示：
 * 1. 移除石头 [2,2] ，因为它和 [2,0] 同行。
 * 2. 移除石头 [2,0] ，因为它和 [0,0] 同列。
 * 3. 移除石头 [0,2] ，因为它和 [0,0] 同行。
 * 石头 [0,0] 和 [1,1] 不能移除，因为它们没有与另一块石头同行/列。
 * 
 * 示例 3：
 * 
 * 
 * 输入：stones = [[0,0]]
 * 输出：0
 * 解释：[0,0] 是平面上唯一一块石头，所以不可以移除它。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 i, yi 
 * 不会有两块石头放在同一个坐标点上
 * 
 * 
 */

// @lc code=start
#include <stdbool.h>

#define MAX_N 20010

int g_fa[MAX_N];
int g_cnt = 0;

void init()
{
    g_cnt = 0;
    for (int i = 0; i < MAX_N; ++i) {
        g_fa[i] = -1;
    }
}

int find(int u) 
{
    if (g_fa[u] == -1) {
        ++g_cnt;
        printf("u=%d\n", u);
        return g_fa[u] = u;
    }
    return u == g_fa[u] ? u : (g_fa[u] = find(g_fa[u]));
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) {
        return;
    }
    g_fa[u] = g_fa[v];
    --g_cnt;
}

bool same(int u, int v)
{
    return find(u) == find(v);
}

int removeStones(int** stones, int stonesSize, int* stonesColSize){
    init();
    for (int i = 0; i < stonesSize; ++i) {
        int row = stones[i][0];
        int col = stones[i][1] + 10001;
        merge(row, col);
    }
    return stonesSize - g_cnt;
}
// @lc code=end

