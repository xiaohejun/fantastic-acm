/*
 * @lc app=leetcode.cn id=839 lang=c
 *
 * [839] 相似字符串组
 *
 * https://leetcode-cn.com/problems/similar-string-groups/description/
 *
 * algorithms
 * Hard (36.80%)
 * Likes:    99
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 23.7K
 * Testcase Example:  '["tars","rats","arts","star"]'
 *
 * 如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y
 * 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。
 * 
 * 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与
 * "tars"，"rats"，或 "arts" 相似。
 * 
 * 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。注意，"tars" 和 "arts"
 * 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
 * 
 * 给你一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。请问 strs 中有多少个相似字符串组？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["tars","rats","arts","star"]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["omv","ovm"]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * sum(strs[i].length) 
 * strs[i] 只包含小写字母。
 * strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。
 * 
 * 
 * 
 * 
 * 备注：
 * 
 * 字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。
 * 
 */

// @lc code=start

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int n;
    int *fa;
    int size;
} UnionSet;

UnionSet* createUnionSet(int size)
{
    UnionSet *set = malloc(sizeof(UnionSet));
    set->n = size;
    set->size = size;
    set->fa = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        set->fa[i] = i;
    }
    return set;
}

int unionSetFind(UnionSet *set, int u)
{
    return u == set->fa[u] ? u : (set->fa[u] = unionSetFind(set, set->fa[u]));
}

void unionSetMerge(UnionSet *set, int u, int v)
{
    u = unionSetFind(set, u);
    v = unionSetFind(set, v);
    if (u != v) {
        set->fa[u] = v;
        set->size--;
    }
}

bool unionSetSame(UnionSet *set, int u, int v)
{
    return unionSetFind(set, u) == unionSetFind(set, v); 
}


inline int unionSetGetSize(UnionSet *set)
{
    return set->size;
}

void freeUnionSet(UnionSet **set)
{
    if ((*set)->fa != NULL) {
        free((*set)->fa);
        (*set)->fa = NULL;
    }
    free((*set));
    *set = NULL;
}


bool isXORStr(char *strA, char *strB)
{
    int len = strlen(strA);
    int idx1 = -1;
    int idx2 = -1;
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (strA[i] != strB[i]) {
            ++cnt;
            if (idx1 == -1) {
                idx1 = i;
            } else if (idx2 == -1) {
                idx2 = i;
            }
        }
    }
    if (cnt == 0) {
        return true;
    }
    if (cnt == 2 && strA[idx1] == strB[idx2] && strA[idx2] == strB[idx1]) {
        return true;
    }
    return false;
}

int numSimilarGroups(char ** strs, int strsSize){
    UnionSet *set = createUnionSet(strsSize);
    for (int i = 0; i < strsSize; ++i) {
        for (int j = i + 1; j < strsSize; ++j) {
            if (isXORStr(strs[i], strs[j])) {
                unionSetMerge(set, i, j);
            }
        }
    }
    int ans = unionSetGetSize(set);
    freeUnionSet(&set);
    return ans;
}
// @lc code=end