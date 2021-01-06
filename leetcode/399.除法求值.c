/*
 * @lc app=leetcode.cn id=399 lang=c
 *
 * [399] 除法求值
 *
 * https://leetcode-cn.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (55.12%)
 * Likes:    403
 * Dislikes: 0
 * Total Accepted:    26.2K
 * Total Submissions: 44.4K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和
 * values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
 * 
 * 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj
 * = ? 的结果作为答案。
 * 
 * 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
 * 
 * 
 * 
 * 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * 解释：
 * 条件：a / b = 2.0, b / c = 3.0
 * 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
 * queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * 输出：[3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * 输出：[0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * equations[i].length == 2
 * 1 i.length, Bi.length 
 * values.length == equations.length
 * 0.0 < values[i] 
 * 1 
 * queries[i].length == 2
 * 1 j.length, Dj.length 
 * Ai, Bi, Cj, Dj 由小写英文字母与数字组成
 * 
 * 
 */

// @lc code=start

#include <stdlib.h>
#include <string.h>
#define MAX_N 45
#define MAX_LEN 7
int g_topo[MAX_N][MAX_N];
double g_cost[MAX_N][MAX_N];
char g_hashTable[MAX_N][MAX_LEN];
int g_idx = 0;
int g_has[MAX_N];

#define dbg(fmt, ...) \
    printf("[%s:%d] : " fmt "\n", __func__, __LINE__, ##__VA_ARGS__)

int hash(char *str, int mode)
{
    for (int i = 0; i < g_idx; ++i) {
        if (strcmp(g_hashTable[i], str) == 0) {
            return i;
        }
    }
    if (mode == 0) { // add
        strcpy(g_hashTable[g_idx++], str);
        return g_idx - 1;
    }
    return -1;
}

int dfs(int u, int v, double *ret)
{
    g_has[u] = 1;
    if (u == v) {
        return 1;
    }
    for (int i = 0; i < g_idx; ++i) {
        if (g_topo[u][i] && !g_has[i]) {
            if (dfs(i, v, ret)) {
                (*ret) *= g_cost[u][i];
                return 1;
            }
        }
    }
    return 0;
}

double qry(char *fromStr, char *toStr)
{
    int from = hash(fromStr, 1);
    int to = hash(toStr, 1);
    if (from == -1 || to == -1) {
        return -1.0;
    }
    if (from == to) {
        return 1.0;
    }
    double ret = 1.0;
    memset(g_has, 0, sizeof(g_has));
    if (dfs(from, to, &ret)) {
        return ret;
    }
    return -1.0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* calcEquation
(
    char *** equations, 
    int equationsSize, 
    int* equationsColSize, 
    double* values, 
    int valuesSize, 
    char *** queries, 
    int queriesSize, 
    int* queriesColSize, 
    int* returnSize
){
    memset(g_topo, 0, sizeof(g_topo));
    g_idx = 0;
    for (int i = 0; i < equationsSize; ++i) {
        int u = hash(equations[i][0], 0);
        int v = hash(equations[i][1], 0);
        g_topo[u][v] = 1;
        g_cost[u][v] = values[i];
        g_topo[v][u] = 1;
        g_cost[v][u] = 1.0 / values[i];
    }
    *returnSize = queriesSize;
    double *ret = malloc(sizeof(double) * queriesSize);
    for (int i = 0; i < queriesSize; ++i) {
        ret[i] = qry(queries[i][0], queries[i][1]);
    }
    return ret;
}

// @lc code=end

