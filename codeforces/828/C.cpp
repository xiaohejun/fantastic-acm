#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    s += s;

    vector<int> f(n, 0);
    // 最近的g
    for (int i = n - 1; i < 2 * n; ++i) {
        if (s[i] == 'g') {
            f[n - 1] = i - (n - 1);
            break;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == 'g') {
            f[i] = 0;
        } else {
            f[i] = f[i + 1] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) {
            ans = max(ans, f[i]);
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
