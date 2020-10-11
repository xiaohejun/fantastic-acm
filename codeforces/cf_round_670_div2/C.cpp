#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "[" << __func__ << ":" << __LINE__ << "] : " << #x"=" << x << endl;

const int MAX_N = 1e5+100;
vector<int> G[MAX_N];
int n;
int sum[MAX_N];
int weight[MAX_N];
bool has[MAX_N];

void dfs(int u) {
    has[u] = true;
    sum[u] = 1;
    int mx = 0;
    for (int v : G[u]) {
        if (has[v]) continue;
        dfs(v);
        sum[u] += sum[v];
        mx = max(mx, sum[v]);
    }
    mx = max(mx, n - sum[u]);
    weight[u] = mx;
}

bool dfsFind(int u, int fa, int &ansx, int &ansy, int exc) {
    int cnt = G[u].size();
    if (cnt == 1) {
        if (fa != -1) {
            ansx = fa;
            ansy = u;
        } else {
            ansx = u;
            ansy = G[u][0];
        }
        return true;
    }
    for (int v : G[u]) {
        if (v == fa || v == exc) continue;
        if (dfsFind(v, u, ansx, ansy, exc)) {
            return true;
        }
    }
    return false;
}

void solve() {
    dfs(1);
    int mn = n;
    for (int i = 1; i <= n; ++i) {
        mn = min(mn, weight[i]);
    }
    vector<int> id;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (weight[i] == mn) {
            ++cnt;
            id.push_back(i);
        }
    }
    int ansx, ansy;
    dfsFind(id[0], -1, ansx, ansy, (cnt > 1 ? id[1] : -1));
    cout << ansx << " " << ansy << endl;
    if (cnt == 1 || n == 2) {
        cout << ansx << " " << ansy << endl;
    } else {
        cout << id[1] << " " << ansy << endl;
    }
}

int main() {
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            sum[i] = 0;
            has[i] = false;
        }
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        solve();
    }
    return 0;
}
