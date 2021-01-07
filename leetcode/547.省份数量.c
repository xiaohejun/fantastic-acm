/*
 * @lc app=leetcode.cn id=547 lang=c
 *
 * [547] 省份数量
 *
 * https://leetcode-cn.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (59.36%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    105.7K
 * Total Submissions: 173.5K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * 
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c
 * 间接相连。
 * 
 * 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
 * 
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而
 * isConnected[i][j] = 0 表示二者不直接相连。
 * 
 * 返回矩阵中 省份 的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] 为 1 或 0
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 * 
 * 
 * 
 * 
 */

// @lc code=start

#define MAX_N 250
int g_fa[MAX_N];

int find(int u)
{
    return u == g_fa[u] ? u : (g_fa[u] = find(g_fa[u]));
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    g_fa[u] = v;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    for (int i = 0; i < MAX_N; ++i) {
        g_fa[i] = i;
    }
    for (int i = 0; i < isConnectedSize; ++i) {
        for (int j = i; j < isConnectedColSize[i]; ++j) {
            if (isConnected[i][j]) {
                merge(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < isConnectedSize; ++i) {
        if (g_fa[i] == i) {
            ++ans;
        }
    }
    return ans;
}
// @lc code=end

