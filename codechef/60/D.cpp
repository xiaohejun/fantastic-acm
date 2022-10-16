#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

const int MOD = 998244353;

const int MAX_N = 1100;
int dp[MAX_N][MAX_N];

void solve()
{
    int n, m;
    cin >> n >> m;
    int total = n + m - 1;
    if (total & 1) {
        cout << "0" << endl;
        return;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = 0;
        }
    }

    dp[1][1] = 1;
    int dir[2][2] = {
        {0, 1},
        {1, 0}
    };

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 2; ++k) {
                int ii = i + dir[k][0];
                int jj = j + dir[k][1];
                if (1 <= ii && ii <= n && 1 <= jj && jj <= m) {
                    if (dp[ii][jj] + dp[i][j] < dp[ii][jj]) {
                        dbg("over")
                        dbg(dp[ii][jj])
                    }
                    dp[ii][jj] += dp[i][j]; // TODO mod
                }
            }
        }
    }

    dbg(dp[n][m])

    int h = total / 2;
    dbg(total)
    dbg(h)
}

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
