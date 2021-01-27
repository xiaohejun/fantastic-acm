/*
 * @lc app=leetcode.cn id=1579 lang=c
 *
 * [1579] 保证图可完全遍历
 *
 * https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
 *
 * algorithms
 * Hard (46.22%)
 * Likes:    95
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 21.1K
 * Testcase Example:  '4\n[[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]'
 *
 * Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：
 * 
 * 
 * 类型 1：只能由 Alice 遍历。
 * 类型 2：只能由 Bob 遍历。
 * 类型 3：Alice 和 Bob 都可以遍历。
 * 
 * 
 * 给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei
 * 的双向边。请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob
 * 都可以到达所有其他节点，则认为图是可以完全遍历的。
 * 
 * 返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
 * 输出：2
 * 解释：如果删除 [1,1,2] 和 [1,1,3] 这两条边，Alice 和 Bob
 * 仍然可以完全遍历这个图。再删除任何其他的边都无法保证图可以完全遍历。所以可以删除的最大边数是 2 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
 * 输出：0
 * 解释：注意，删除任何一条边都会使 Alice 和 Bob 无法完全遍历这个图。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
 * 输出：-1
 * 解释：在当前图中，Alice 无法从其他节点到达节点 4 。类似地，Bob 也不能达到节点 1 。因此，图无法完全遍历。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^5
 * 1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
 * edges[i].length == 3
 * 1 <= edges[i][0] <= 3
 * 1 <= edges[i][1] < edges[i][2] <= n
 * 所有元组 (typei, ui, vi) 互不相同
 * 
 * 
 */

// @lc code=start

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int type, u, v;
} Edge;

typedef struct {
    int n;
    int *fa;
} UnionSet;

int EdgeCmp(const void *a, const void *b)
{
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeB->type - edgeA->type;
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

bool buildPeopleUnionSet(UnionSet *set, int *cnt, int n, Edge *edge)
{
    if ((*cnt) < n - 1 && !UnionSetSame(set, edge->u, edge->v)) {
        UnionSetMerge(set, edge->u, edge->v);
        (*cnt)++;
        return true;
    }
    return false;
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize){
    Edge *edgeList = malloc(sizeof(Edge) * edgesSize);
    for (int i = 0; i < edgesSize; ++i) {
        edgeList[i] = (Edge){edges[i][0], edges[i][1] - 1, edges[i][2] - 1};
    }
    qsort(edgeList, edgesSize, sizeof(Edge), EdgeCmp);
    UnionSet *aliceSet = CreateUnionSet(n);
    UnionSet *bobSet = CreateUnionSet(n);
    int aCnt = 0;
    int bCnt = 0;
    int usedCnt = 0;
    for (int i = 0; i < edgesSize && (aCnt != n - 1 || bCnt != n - 1) ; ++i) {
        Edge *edge = &edgeList[i];
        if (edge->type == 1) { // Alice
            if (buildPeopleUnionSet(aliceSet, &aCnt, n, edge)) {
                ++usedCnt;
            }
        } else if (edge->type == 2) { // Bob
            if (buildPeopleUnionSet(bobSet, &bCnt, n, edge)) {
                ++usedCnt;
            }
        } else { // both
            bool aliceOk = buildPeopleUnionSet(aliceSet, &aCnt, n, edge);
            bool bobOk = buildPeopleUnionSet(bobSet, &bCnt, n, edge); 
            if (aliceOk || bobOk) {
                ++usedCnt;
            }
        }
    }
    free(edgeList);
    FreeUnionSet(&aliceSet);
    FreeUnionSet(&bobSet);
    bool bothCan = (aCnt == n - 1) && (bCnt == n - 1);
    return bothCan ? edgesSize - usedCnt : -1;
}
// @lc code=end

