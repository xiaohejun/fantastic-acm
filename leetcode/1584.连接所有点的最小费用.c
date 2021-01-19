/*
 * @lc app=leetcode.cn id=1584 lang=c
 *
 * [1584] 连接所有点的最小费用
 *
 * https://leetcode-cn.com/problems/min-cost-to-connect-all-points/description/
 *
 * algorithms
 * Medium (51.82%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    17.9K
 * Total Submissions: 27K
 * Testcase Example:  '[[0,0],[2,2],[3,10],[5,2],[7,0]]'
 *
 * 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。
 * 
 * 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示
 * val 的绝对值。
 * 
 * 请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * 输出：20
 * 解释：
 * 
 * 我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
 * 注意到任意两个点之间只有唯一一条路径互相到达。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：points = [[3,12],[-2,5],[-4,1]]
 * 输出：18
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：points = [[0,0],[1,1],[1,0],[-1,1]]
 * 输出：4
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：points = [[-1000000,-1000000],[1000000,1000000]]
 * 输出：4000000
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：points = [[0,0]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= points.length <= 1000
 * -10^6 <= xi, yi <= 10^6
 * 所有点 (xi, yi) 两两不同。
 * 
 * 
 */

// @lc code=start

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int u, v, cost;
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


int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    Edge *edges = malloc(sizeof(Edge) * pointsSize * pointsSize);
    int idx = 0;
    for (int i = 0; i < pointsSize; ++i) {
        for (int j = i + 1; j < pointsSize; ++j) {
            int detx = abs(points[i][0] - points[j][0]);
            int dety = abs(points[i][1] - points[j][1]);
            int dis = detx + dety;
            edges[idx++] = (Edge){i, j, dis};
            edges[idx++] = (Edge){j, i, dis};
        }
    }
    qsort(edges, idx, sizeof(Edge), EdgeCmp);
    UnionSet *set = CreateUnionSet(pointsSize);
    int cost = 0;
    int need = pointsSize - 1;
    for (int i = 0; i < idx && need; ++i) {
        Edge *edge = &edges[i];
        if (!UnionSetSame(set, edge->u, edge->v)) {
            UnionSetMerge(set, edge->u, edge->v);
            cost += edge->cost;
            --need;
        }
    }
    FreeUnionSet(&set);
    return cost;
}
// @lc code=end

