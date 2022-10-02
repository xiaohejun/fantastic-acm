#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x) ;
#endif

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    vector<char> mn(n, '9');
    mn[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        mn[i] = min(mn[i + 1], s[i]);
    }

    string ans = "";
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; ++i) {
        int up = mn[i] - '0';
        for (int j = 0; j < up; ++j) {
            while (cnt[j]) {
                ans += (char('0' + j));
                cnt[j]--;
            }
        }
        if (s[i] == mn[i]) {
            ans += s[i];
        } else {
            int d = s[i] - '0';
            cnt[min(d+1, 9)]++;
        }
    }
    dbg(s)
    dbg(ans)

    for (int j = 0; j <= 9; ++j) {
        while (cnt[j]) {
            ans += (char('0' + j));
            cnt[j]--;
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