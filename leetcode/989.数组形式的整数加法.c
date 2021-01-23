/*
 * @lc app=leetcode.cn id=989 lang=c
 *
 * [989] 数组形式的整数加法
 *
 * https://leetcode-cn.com/problems/add-to-array-form-of-integer/description/
 *
 * algorithms
 * Easy (44.31%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    38.2K
 * Total Submissions: 80.2K
 * Testcase Example:  '[1,2,0,0]\n34'
 *
 * 对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
 * 
 * 给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [1,2,0,0], K = 34
 * 输出：[1,2,3,4]
 * 解释：1200 + 34 = 1234
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = [2,7,4], K = 181
 * 输出：[4,5,5]
 * 解释：274 + 181 = 455
 * 
 * 
 * 示例 3：
 * 
 * 输入：A = [2,1,5], K = 806
 * 输出：[1,0,2,1]
 * 解释：215 + 806 = 1021
 * 
 * 
 * 示例 4：
 * 
 * 输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
 * 输出：[1,0,0,0,0,0,0,0,0,0,0]
 * 解释：9999999999 + 1 = 10000000000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * 0 <= A[i] <= 9
 * 0 <= K <= 10000
 * 如果 A.length > 1，那么 A[0] != 0
 * 
 * 
 */

// @lc code=start

inline void swap(int *a, int *b)
{
    int *t = *a;
    *a = *b;
    *b = *t;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int now = ASize + 10;
    int *ret = malloc(sizeof(int) * now);
    int idx = 0;
    for (int i = ASize - 1; i >= 0; --i) {
        int sum = K + A[i];
        int mod = sum % 10;
        int rem = sum / 10;
        ret[idx++] = mod;
        K = rem;
    }
    while (K) {
        ret[idx++] = K % 10;
        K /= 10;
    }
    int l = 0, r = idx - 1;
    while (l <= r) {
        swap(&ret[l], &ret[r]);
        ++l;
        --r;
    }
    *returnSize = idx;
    return ret;
}


// @lc code=end

