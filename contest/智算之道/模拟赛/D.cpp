#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 1e5+100;
const int INF = 1e9;
int dis[MAX_N][2];
int n, m, q;
vector<int> G[MAX_N];

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        dis[i][0] = dis[i][1] = INF;
    }
    queue<pair<int, int>> que;
    if (G[1].size()) {
        dis[1][0] = 0;
        que.push(make_pair(1, 0));
    }
    while (!que.empty()) {
        pair<int, int> u = que.front();
        que.pop();
        for (int v : G[u.first]) {
            if (dis[v][u.second ^ 1] > dis[u.first][u.second]+ 1) {
                dis[v][u.second ^ 1] = dis[u.first][u.second] + 1;
                que.push(make_pair(v, u.second ^ 1));
            }
        }
    }
    while (q--) {
        cin >> u >> v;
        cout << (v >= dis[u][v&1] ? "Yes" : "No") << endl;
    }
    return 0;
}
