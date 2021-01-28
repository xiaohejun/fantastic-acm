/*
 * @lc app=leetcode.cn id=724 lang=c
 *
 * [724] 寻找数组的中心索引
 *
 * https://leetcode-cn.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (39.63%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    99.3K
 * Total Submissions: 234.3K
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * 给你一个整数数组 nums，请编写一个能够返回数组 “中心索引” 的方法。
 * 
 * 数组 中心索引 是数组的一个索引，其左侧所有元素相加的和等于右侧所有元素相加的和。
 * 
 * 如果数组不存在中心索引，返回 -1 。如果数组有多个中心索引，应该返回最靠近左边的那一个。
 * 
 * 注意：中心索引可能出现在数组的两端。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1, 7, 3, 6, 5, 6]
 * 输出：3
 * 解释：
 * 索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11) 相等。
 * 同时, 3 也是第一个符合要求的中心索引。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1, 2, 3]
 * 输出：-1
 * 解释：
 * 数组中不存在满足此条件的中心索引。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [2, 1, -1]
 * 输出：0
 * 解释：
 * 索引 0 左侧不存在元素，视作和为 0 ；右侧数之和为 1 + (-1) = 0 ，二者相等。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [0, 0, 0, 0, 1]
 * 输出：4
 * 解释：
 * 索引 4 左侧数之和为 0 ；右侧不存在元素，视作和为 0 ，二者相等。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums 的长度范围为 [0, 10000]。
 * 任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。
 * 
 * 
 */

// @lc code=start



int getSumLR(int *sum, int l, int r)
{
    return sum[r] - sum[l - 1];
}

int pivotIndex(int* nums, int n){
    int *sum = malloc(sizeof(int) * (n + 1));
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + nums[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (getSumLR(sum, 1, i - 1) == getSumLR(sum, i + 1, n)) {
            return i - 1;
        }
    }
    free(sum);
    return -1;
}
// @lc code=end

