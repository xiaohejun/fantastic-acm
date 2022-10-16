#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt[26] = {0};
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
    }

    // for (int i = 0; i < 26; ++i) {
    //     dbg(cnt[i])
    // }

    string ans(k, '#');
    int m = n / k;
    dbg(m)
    for (int i = 0; i < k; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            if (cur >= 25 || cnt[cur] == 0) {
                ans[i] = (char)('a' + cur);
                break;
            } else {
                cnt[cur]--;
                cur++;
            }
        }
        if (ans[i] == '#') {
            ans[i] = (char)('a' + cur);
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
