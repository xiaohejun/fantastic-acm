#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 4100;
char s[MAX_N];
vector<int> tree[MAX_N];
int cnt[MAX_N][2];

void dfs(int u)
{
    if (s[u - 1] == 'W') {
        ++cnt[u][0];
    } else {
        ++cnt[u][1];
    }
    for (int v : tree[u]) {
        dfs(v);
        cnt[u][0] += cnt[v][0];
        cnt[u][1] += cnt[v][1];
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
        cnt[i][0] = 0;
        cnt[i][1] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        tree[x].push_back(i);
    }
    cin >> s;
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << cnt[i][0] << " " << cnt[i][1] << endl;
        if (cnt[i][0] == cnt[i][1]) {
            ++ans;
        }
    }
    cout << ans << endl;
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
