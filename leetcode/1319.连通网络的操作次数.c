/*
 * @lc app=leetcode.cn id=1319 lang=c
 *
 * [1319] 连通网络的操作次数
 *
 * https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/description/
 *
 * algorithms
 * Medium (52.54%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    17.1K
 * Total Submissions: 28.6K
 * Testcase Example:  '4\n[[0,1],[0,2],[1,2]]'
 *
 * 用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] =
 * [a, b] 连接了计算机 a 和 b。
 * 
 * 网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。
 * 
 * 给你这个计算机网络的初始布线
 * connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回
 * -1 。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：n = 4, connections = [[0,1],[0,2],[1,2]]
 * 输出：1
 * 解释：拔下计算机 1 和 2 之间的线缆，并将它插到计算机 1 和 3 上。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
 * 输出：-1
 * 解释：线缆数量不足。
 * 
 * 
 * 示例 4：
 * 
 * 输入：n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^5
 * 1 <= connections.length <= min(n*(n-1)/2, 10^5)
 * connections[i].length == 2
 * 0 <= connections[i][0], connections[i][1] < n
 * connections[i][0] != connections[i][1]
 * 没有重复的连接。
 * 两台计算机不会通过多条线缆连接。
 * 
 * 
 */

// @lc code=start

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int idx, u, v, cost;
} Edge;

typedef struct {
    int n;
    int size;
    int *fa;
} UnionSet;

int EdgeCmp(const void *a, const void *b)
{
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->cost - edgeB->cost;
}

UnionSet* CreateUnionSet(int size)
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

int UnionSetFind(UnionSet *set, int u)
{
    return u == set->fa[u] ? u : (set->fa[u] = UnionSetFind(set, set->fa[u]));
}

void UnionSetMerge(UnionSet *set, int u, int v)
{
    u = UnionSetFind(set, u);
    v = UnionSetFind(set, v);
    if (u != v) {
        set->size--;
        set->fa[u] = v;
    }
}

bool UnionSetSame(UnionSet *set, int u, int v)
{
    return UnionSetFind(set, u) == UnionSetFind(set, v); 
}

void FreeUnionSet(UnionSet **set)
{
    if ((*set)->fa != NULL) {
        free((*set)->fa);
        (*set)->fa = NULL;
    }
    free((*set));
    *set = NULL;
}

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
    if (connectionsSize < n - 1) {
        return -1;
    }
    UnionSet *set = CreateUnionSet(n);
    int remCnt = 0;
    for (int i = 0; i < connectionsSize; ++i) {
        if (UnionSetSame(set, connections[i][0], connections[i][1])) {
            ++remCnt;
            continue;
        }
        UnionSetMerge(set, connections[i][0], connections[i][1]);
    }
    int ret = remCnt >= set->size - 1 ? set->size - 1 : -1; 
    FreeUnionSet(&set);
    return ret;
}
// @lc code=end

