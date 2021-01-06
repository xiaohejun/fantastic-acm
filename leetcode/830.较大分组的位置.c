/*
 * @lc app=leetcode.cn id=830 lang=c
 *
 * [830] 较大分组的位置
 *
 * https://leetcode-cn.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (48.15%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    43.5K
 * Total Submissions: 80.4K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * 在一个由小写字母构成的字符串 s 中，包含由一些连续的相同字符所构成的分组。
 * 
 * 例如，在字符串 s = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。
 * 
 * 分组可以用区间 [start, end] 表示，其中 start 和 end 分别表示该分组的起始和终止位置的下标。上例中的 "xxxx"
 * 分组用区间表示为 [3,6] 。
 * 
 * 我们称所有包含大于或等于三个连续字符的分组为 较大分组 。
 * 
 * 找到每一个 较大分组 的区间，按起始位置下标递增顺序排序后，返回结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abbxxxxzzy"
 * 输出：[[3,6]]
 * 解释："xxxx" 是一个起始于 3 且终止于 6 的较大分组。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abc"
 * 输出：[]
 * 解释："a","b" 和 "c" 均不是符合要求的较大分组。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "abcdddeeeeaabbbcd"
 * 输出：[[3,5],[6,9],[12,14]]
 * 解释：较大分组为 "ddd", "eeee" 和 "bbb"
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "aba"
 * 输出：[]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅含小写英文字母
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char * s, int* returnSize, int** returnColumnSizes){
    int len = strlen(s);
    (*returnSize) = 0;
    for (int i = 0; i < len; ) {
        char c = s[i];
        int cnt = 0;
        while (i < len && s[i] == c) {
            ++cnt;
            ++i;
        }
        if (cnt >= 3) {
            (*returnSize)++;
        }
    }
    (*returnColumnSizes) = malloc(sizeof(int) * (*returnSize));
    int **ret = malloc(sizeof(int *) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = 2;
        ret[i] = malloc(sizeof(int) * 2);
    }
    int idx = 0;
    for (int i = 0; i < len;) {
        char c = s[i];
        int cnt = 0;
        int l = i;
        while (i < len && s[i] == c) {
            ++cnt;
            ++i;
        }
        if (cnt >= 3) {
            ret[idx][0] = l;
            ret[idx][1] = l + cnt - 1;
            idx++;
        }
    }
    return ret;
}
// @lc code=end

