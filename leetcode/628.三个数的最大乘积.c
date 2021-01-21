/*
 * @lc app=leetcode.cn id=628 lang=c
 *
 * [628] 三个数的最大乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (49.98%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    37.4K
 * Total Submissions: 74.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,3]
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,3,4]
 * 输出: 24
 * 
 * 
 * 注意:
 * 
 * 
 * 给定的整型数组长度范围是[3,10^4]，数组中所有的元素范围是[-1000, 1000]。
 * 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
 * 
 * 
 */

// @lc code=start

#include <stdlib.h>

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int maximumProduct(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int mx = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    mx = max(mx, nums[0] * nums[1] * nums[numsSize - 1]);
    return mx;
}
// @lc code=end

