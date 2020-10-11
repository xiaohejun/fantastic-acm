#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void dfs(vector<int> *G, vector<bool> &has, vector<int> &topo, int u) {
    has[u] = true;
    for (int v : G[u]) {
        if (!has[v]) {
            dfs(G, has, topo, v);
        }
    }
    topo.push_back(u);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> G[n];
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        --y;
        if (t == 1) {
            G[x].push_back(y);
        }
        edges.push_back(make_pair(x, y));
    }
    vector<bool> has(n, false);
    vector<int> topo;
    for (int i = 0; i < n; ++i) {
        if (!has[i]) dfs(G, has, topo, i);
    }
    reverse(topo.begin(), topo.end());
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[topo[i]] = i;
    }
    bool bad = false;
    for (int u = 0; u < n && !bad; ++u) {
        for (int v : G[u]) {
            if (pos[u] > pos[v]) {
                bad = true;
                break;
            }
        }
    }
    if (bad) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto it : edges) {
            int x = it.first;
            int y = it.second;
            if (pos[x] < pos[y]) {
                cout << x + 1 << " " << y + 1 << endl;
            } else {
                cout << y + 1 << " " << x + 1 << endl;
            }
        }
    }
} 


int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();

    

    return 0; 
}














