/*
 * @lc app=leetcode.cn id=228 lang=c
 *
 * [228] 汇总区间
 *
 * https://leetcode-cn.com/problems/summary-ranges/description/
 *
 * algorithms
 * Easy (53.79%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    26.7K
 * Total Submissions: 47.2K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * 给定一个无重复元素的有序整数数组 nums 。
 * 
 * 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于
 * nums 的数字 x 。
 * 
 * 列表中的每个区间范围 [a,b] 应该按如下格式输出：
 * 
 * 
 * "a->b" ，如果 a != b
 * "a" ，如果 a == b
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [0,1,2,4,5,7]
 * 输出：["0->2","4->5","7"]
 * 解释：区间范围是：
 * [0,2] --> "0->2"
 * [4,5] --> "4->5"
 * [7,7] --> "7"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,2,3,4,6,8,9]
 * 输出：["0","2->4","6","8->9"]
 * 解释：区间范围是：
 * [0,0] --> "0"
 * [2,4] --> "2->4"
 * [6,6] --> "6"
 * [8,9] --> "8->9"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [-1]
 * 输出：["-1"]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums = [0]
 * 输出：["0"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -2^31 
 * nums 中的所有值都 互不相同
 * nums 按升序排列
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    int idx = 0;
    int *ans = malloc(sizeof(int) * 2 * numsSize);
    int id = 0;
    for (int i = 0; i < numsSize;) {
        int cnt = 0;
        int val = nums[i];
        while (i < numsSize && nums[i] == val + cnt) {
            ++cnt;
            ++i;
        }
        ans[id++] = val;
        ans[id++] = val + (cnt - 1);
        idx++;
    }
    *returnSize = idx;
    char **ret = malloc(sizeof(char *) * (*returnSize));
    const int retLen = 30;
    for (int i = 0; i < idx; ++i) {
        ret[i] = malloc(sizeof(char) * retLen);
        if (ans[2 * i] == ans[2 * i + 1]) {
            sprintf(ret[i], "%d", ans[2 * i]);
        } else {
            sprintf(ret[i], "%d->%d", ans[2 * i], ans[2 * i + 1]);
        }
    }
    return ret;
}
// @lc code=end

