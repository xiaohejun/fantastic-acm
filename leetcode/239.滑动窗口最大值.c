/*
 * @lc app=leetcode.cn id=239 lang=c
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.30%)
 * Likes:    742
 * Dislikes: 0
 * Total Accepted:    106.1K
 * Total Submissions: 215.3K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,-1], k = 1
 * 输出：[1,-1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [9,11], k = 2
 * 输出：[11]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums = [4,-2], k = 2
 * 输出：[4]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 1 
 * 
 * 
 */

// @lc code=start

#include <bits/stdc++.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    (*returnSize) = numsSize - k + 1;
    int *ans = malloc(*returnSize);
    assert(ans != NULL);
    
    return ans;
}
// @lc code=end

