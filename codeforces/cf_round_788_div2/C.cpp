#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

const int MOD = 1e9 + 7;
const int MAX_N = 1e5+10;
int a[MAX_N];
int b[MAX_N];
int c[MAX_N];
int cnt[MAX_N];
bool has[MAX_N];
int n;
int fa[MAX_N];

void init()
{
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        cnt[i] = 1;
        has[i] = false;
    }
}

int find(int u)
{
    return fa[u] = (u == fa[u] ? u : find(fa[u]));
}

void unoinset(int u, int v)
{
    u = find(u);
    v = find(v);
    int x = min(u, v);
    int y = max(u, v);
    if (x == y) {
        return;
    }
    if (has[x]) {
        has[y] = true;
    }
    if (has[y]) {
        has[x] = true;
    }
    fa[x] = y;
    cnt[y]++;
}

void solve()
{
    cin >> n;
    dbg(n)
    init();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] != 0) {
            has[c[i]] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] == 0) {
            unoinset(a[i], b[i]);
        }
    }
    int setNum = 0;
    for (int i = 1; i <= n; ++i) {
        if (has[i]) {
            continue;
        }
        int u = find(i);
        if (u == i && cnt[u] > 1) {
            setNum++;
        }
    }
    LL ans = 1;
    for (int i = 1; i <= setNum; ++i) {
        ans = (ans * 2LL) % MOD;
    }
    cout << ans << endl;
}

/*
dp[i][0/1] 表示第前i个，第i个选择0/1的方案数
if 已经确定
    dp[i][j] = 1
else  
    dp[i][j^0] = 0

1 2 3
3 1 2
0 0 0

dp[0][0] = 1 ()
dp[0][0] = 1

1 2 3 4
2 3 4 1
0 0 0 0

1  1
1, 2

1  
2, 

1 2 3
2 1 3
0 0 0
*/

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

/*
1 2 3 4 5 6 7
2 3 1 7 6 5 4
0 0 0 0 0 0 0

1 2 3 4 5 6 7

*/
