#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

const int MAX_N = 2e5+10;
int a[MAX_N];
int dp[MAX_N][2];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '0') {
            // 没得移动
            dp[i][1] = 0;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        } else {
            // 不移动
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
            // 移动
            dp[i][0] = max(dp[i - 1][0] + a[i - 1], dp[i - 1][1]);
        }
    }

    if (s[n - 1] == '0') {
        cout << dp[n][0] << endl;
    } else {
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
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
