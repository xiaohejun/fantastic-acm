#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
vector<int> tree[MAX_N];
int cur[2 * MAX_N];
bool has[MAX_N];
int now = 0;

void dfs(int u)
{
    cur[now++] = u;
    for (int v : tree[u]) {
        dfs(v);
    }
    cur[now++] = u;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
        has[i] = false;
    }
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        int u;
        cin >> u;
        if (u == i) {
            root = u;
        } else {
            tree[u].push_back(i);
        }
    }
    now = 0;
    dfs(root);
    // for (int i = 0; i < now; ++i) {
    //     cout << i << " " << cur[i] << endl;
    // }
    vector<vector<int>> ans;
    for (int i = 0; i < now;) {
        if (has[cur[i]]) {
            ++i;
            continue;
        }
        vector<int> v;
        while (i < now && !has[cur[i]]) {
            v.push_back(cur[i]);
            has[cur[i]] = true;
            if (i + 1 < now && cur[i] == cur[i + 1]) {
                break;
            }
            ++i;
        }
        if (v.size()) {
            ans.push_back(v);
        }
    } 
    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v.size() << endl;
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
