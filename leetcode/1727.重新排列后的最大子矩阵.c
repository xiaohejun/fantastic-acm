/*
 * @lc app=leetcode.cn id=1727 lang=c
 *
 * [1727] 重新排列后的最大子矩阵
 *
 * https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/description/
 *
 * algorithms
 * Medium (54.25%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    2.3K
 * Total Submissions: 4.3K
 * Testcase Example:  '[[0,0,1],[1,1,1],[1,0,1]]'
 *
 * 给你一个二进制矩阵 matrix ，它的大小为 m x n ，你可以将 matrix 中的 列 按任意顺序重新排列。
 * 
 * 请你返回最优方案下将 matrix 重新排列后，全是 1 的子矩阵面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：matrix = [[0,0,1],[1,1,1],[1,0,1]]
 * 输出：4
 * 解释：你可以按照上图方式重新排列矩阵的每一列。
 * 最大的全 1 子矩阵是上图中加粗的部分，面积为 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：matrix = [[1,0,1,0,1]]
 * 输出：3
 * 解释：你可以按照上图方式重新排列矩阵的每一列。
 * 最大的全 1 子矩阵是上图中加粗的部分，面积为 3 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[1,1,0],[1,0,1]]
 * 输出：2
 * 解释：由于你只能整列整列重新排布，所以没有比面积为 2 更大的全 1 子矩形。
 * 
 * 示例 4：
 * 
 * 
 * 输入：matrix = [[0,0],[0,0]]
 * 输出：0
 * 解释：由于矩阵中没有 1 ，没有任何全 1 的子矩阵，所以面积为 0 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * matrix[i][j] 要么是 0 ，要么是 1 。
 * 
 * 
 */

// @lc code=start

#include <stdlib.h>

int intCmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize){
    int n = matrixSize;
    int m = matrixColSize[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        qsort(matrix[i], m, sizeof(int), intCmp);
        for (int j = m - 1; j >= 0; --j) {
            int h = matrix[i][j];
            int w = m - j;
            ret = max(ret, h * w);
        }
    }
    return ret;
}
// @lc code=end

