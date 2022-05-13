#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

char s[55][10];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int ret = 0;
            for (int k = 0; k < m; ++k) {
                ret += abs(s[j][k] - s[i][k]);
            }
            ans = min(ans, ret);
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
