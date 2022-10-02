#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x) ;
#endif

void solve()
{
    int n;
    cin >> n;
    int mn = 1e8+10;
    int mx = 0;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        mn = min(mn, x[i]);
        mx = max(mx, x[i]);
    }

    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.find(x[i]) == mp.end()) {
            mp[x[i]] = t[i];
        } else {
            mp[x[i]] = max(mp[x[i]], t[i]);
        }
    }

    vector<pair<int, int>> v;
    for (const auto it : mp) {
        v.push_back(it);
    }

    double ans = mn;
    double l = mn - 1;
    double r = mx + 1;
    double ret = 1e19;
    // l <= r l - r <= 0
    while (r - l > 1e-7) {
        double mid = (l + r) / 2.0;
        double total = 0;
        for (auto it : v) {
            total = max(total, abs(1.0 * it.first - mid) + it.second);
        }
        dbg(mid)
        dbg(total)
        if (total < ret) {
            ans = mid;
            ret = total;
            r = mid;
        } else {
            l = mid;
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