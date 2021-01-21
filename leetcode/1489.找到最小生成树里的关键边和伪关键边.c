/*
 * @lc app=leetcode.cn id=1489 lang=c
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 *
 * https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
 *
 * algorithms
 * Hard (49.95%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 13.2K
 * Testcase Example:  '5\n[[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]'
 *
 * 给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi,
 * weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST)
 * 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。
 * 
 * 
 * 请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。
 * 
 * 请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
 * 输出：[[0,1],[2,3,4,5]]
 * 解释：上图描述了给定图。
 * 下图是所有的最小生成树。
 * 
 * 注意到第 0 条边和第 1 条边出现在了所有最小生成树中，所以它们是关键边，我们将这两个下标作为输出的第一个列表。
 * 边 2，3，4 和 5 是所有 MST 的剩余边，所以它们是伪关键边。我们将它们作为输出的第二个列表。
 * 
 * 
 * 示例 2 ：
 * 
 * 
 * 
 * 输入：n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
 * 输出：[[],[0,1,2,3]]
 * 解释：可以观察到 4 条边都有相同的权值，任选它们中的 3 条可以形成一棵 MST 。所以 4 条边都是伪关键边。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 100
 * 1 <= edges.length <= min(200, n * (n - 1) / 2)
 * edges[i].length == 3
 * 0 <= fromi < toi < n
 * 1 <= weighti <= 1000
 * 所有 (fromi, toi) 数对都是互不相同的。
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
    set->fa[u] = v;
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

int MSTExcludeEdge(Edge *edges, int edgeSize, int n, int idx)
{
    UnionSet *set = CreateUnionSet(n);
    int cost = 0;
    int need = n - 1;
    for (int i = 0; i < edgeSize && need; ++i) {
        Edge *edge = &edges[i];
        if (edge->idx == idx) {
            continue;
        }
        if (!UnionSetSame(set, edge->u, edge->v)) {
            UnionSetMerge(set, edge->u, edge->v);
            cost += edge->cost;
            --need;
        }
    }
    FreeUnionSet(&set);
    return cost;
}

int MSTIncludeEdge(Edge *edges, int edgeSize, int n, int idx, Edge *edge)
{
    UnionSet *set = CreateUnionSet(n);
    int cost = edge->cost;
    int need = n - 2;
    UnionSetMerge(set, edge->u, edge->v);
    for (int i = 0; i < edgeSize && need; ++i) {
        Edge *edge = &edges[i];
        if (edge->idx == idx) {
            continue;
        }
        if (!UnionSetSame(set, edge->u, edge->v)) {
            UnionSetMerge(set, edge->u, edge->v);
            cost += edge->cost;
            --need;
        }
    }
    FreeUnionSet(&set);
    return cost;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findCriticalAndPseudoCriticalEdges(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize, int** returnColumnSizes){
    Edge *edgelist = malloc(sizeof(Edge) * edgesSize);
    for (int i = 0; i < edgesSize; ++i) {
        edgelist[i] = (Edge){i, edges[i][0], edges[i][1], edges[i][2]};
    }
    Edge *sortEdgeList = malloc(sizeof(Edge) * edgesSize);
    memcpy(sortEdgeList, edgelist, sizeof(Edge) * edgesSize); 
    qsort(sortEdgeList, edgesSize, sizeof(Edge), EdgeCmp);
    int mstCost = MSTExcludeEdge(sortEdgeList, edgesSize, n, -1);
    *returnSize = 2;
    int **ret = malloc(sizeof(int *) * 2);
    memset(ret, 0, sizeof(int *) * 2);
    (*returnColumnSizes) = malloc(sizeof(int) * 2);
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 0; i < edgesSize; ++i) {
        int nowCost = MSTExcludeEdge(sortEdgeList, edgesSize, n, i);
        if (nowCost > mstCost || nowCost < mstCost) {
            ret[0] = realloc(ret[0], (cnt0 + 1) * sizeof(int));
            ret[0][cnt0] = i;
            ++cnt0;
        }
        if (nowCost == mstCost) {
            nowCost = MSTIncludeEdge(sortEdgeList, edgesSize, n, i, &edgelist[i]);
            if (nowCost == mstCost) {
                ret[1] = realloc(ret[1], (cnt1 + 1) * sizeof(int));
                ret[1][cnt1] = i;
                ++cnt1;
            }
        }
    }
    (*returnColumnSizes)[0] = cnt0;
    (*returnColumnSizes)[1] = cnt1;
    free(edgelist);
    free(sortEdgeList);
    return ret;
}
// @lc code=end
