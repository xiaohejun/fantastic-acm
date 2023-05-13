#include <bits/stdc++.h>
using namespace std;

// 类型定义
typedef long long LL;

#ifndef ONLINE_JUDGE
    #include "../../algo/debug.h"
#else
    #define dbg(x...)
#endif
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int N, M;

struct Edge {
    int v;
    LL cost;
};

vector<vector<Edge>> G;

LL calc_cost(int u, int v, vector<int> &h)
{
    if (h[u] > h[v]) {
        return h[u] - h[v];
    }

    if (h[u] < h[v]) {
        return -2LL * (h[v] - h[u]);
    }

    return 0;
}

typedef pair<LL, int> PLLI;

void dfs(int u, vector<vector<int>> &tree, vector<int> &cnt)
{
    for (int v : tree[u]) {
        cnt[v] = cnt[u] + 1;
        dfs(v, tree, cnt);
    }
}

LL dijkstra(int s, vector<vector<Edge>> &g, const LL &max_cost)
{
    dbg(s)
    // 大的先出
    priority_queue<PLLI, vector<PLLI>, std::less<PLLI>> q;
    int n = g.size() - 1;
    vector<LL> d(n + 1, 0);
    vector<int> prev(n + 1, 0);
    d[s] = LONG_MAX;
    q.push((PLLI){d[s], s});
    while (!q.empty()) {
        PLLI cur = q.top();
        q.pop();
        dbg(cur)

        // 当前的更优秀
        if(d[cur.second] > cur.first) continue;

        for (auto& edge: G[cur.second]) {
            // 松弛边
            LL cost = d[cur.second] + edge.cost;
            // 当前更优秀
            if (cost > d[edge.v]) {
                d[edge.v] = cost;
                prev[edge.v] = cur.second;
                q.push((PLLI){cost, edge.v});
            }
        }
    }

    vector<vector<int>> tree;
    tree.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i != s) {
            tree[prev[i]].push_back(i);
        }
    }

    vector<int> cnt(n + 1, 0);
    dfs(s, tree, cnt);

    LL ans = LONG_MIN;
    for (int i = 1; i <= n; ++i) {
        LL cost = d[i] - LONG_MAX + cnt[i] * max_cost;
        dbg(i, cost)
        ans = max(ans, cost);
    }

    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    fastio;

    cin >> N >> M;
    G.resize(N + 1);
    vector<int> h(N+1, 0);
    for (int i = 1; i <= N; ++i) cin >> h[i];

    LL max_cost = LONG_MIN;
    for (int i = 0; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        LL cost = calc_cost(u, v, h);
        max_cost = max(cost, max_cost);
        G[u].push_back((Edge){v, cost});

        cost = calc_cost(v, u, h);
        max_cost = max(cost, max_cost);
        G[v].push_back((Edge){u, cost});
    }

    // 转成全部负数
    for (auto &u: G) {
        for (auto &edge: u) {
            edge.cost -= max_cost;
            dbg(edge.cost)
        }
    }

    cout << dijkstra(1, G, max_cost) << endl;

    return 0;
}
