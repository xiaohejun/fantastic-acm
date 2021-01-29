/*
 * @lc app=leetcode.cn id=1631 lang=c
 *
 * [1631] 最小体力消耗路径
 *
 * https://leetcode-cn.com/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (35.64%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    16.2K
 * Total Submissions: 33.6K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子
 * (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从
 * 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
 * 
 * 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
 * 
 * 请你返回从左上角走到右下角的最小 体力消耗值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
 * 输出：2
 * 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
 * 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
 * 输出：1
 * 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * 输出：0
 * 解释：上图所示路径不需要消耗任何体力。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == heights.length
 * columns == heights[i].length
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start

#include <stdlib.h>
#include <stdbool.h>

const int INF = 1e9;
int n, m;

inline int idx(int i, int j)
{
    return i * m + j;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void dfs(int *has, int** heights, int i, int j, int limit)
{
    has[i * m + j] = 1;
    if (i == n - 1 && j == m - 1) {
        return;
    }
    int dir[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    for (int k = 0; k < 4; ++k) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (!has[x * m + y] && abs(heights[x][y] - heights[i][j]) <= limit) {
                dfs(has, heights, x, y, limit);
            }
        }
    }
}

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize){
    n = heightsSize;
    m = heightsColSize[0];
    int ori = n * m;
    int l = 0, r = 1000000;
    int ans = 0;
    int *has = malloc(sizeof(int) * (n * m));
    while (l <= r) {
        int mid = (l + r) >> 1;
        memset(has, false, sizeof(int) * n * m);
        dfs(has, heights, 0, 0, mid);
        if (has[n * m - 1]) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    free(has);
    return ans;
}
// @lc code=end

