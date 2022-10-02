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
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
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

    vector<pair<double, double>> v;
    for (const auto it : mp) {
        v.push_back(it);
    }

    double Tmin = 0;
    double Tinit = 0;
    for (auto &it: v) {
        Tmin = max(Tmin, it.second);
        Tinit = max(Tinit, it.first + it.second);
    }

    double l = Tmin;
    double r = Tinit;
    double ans = 0;
    double limit = 1e-7;
    while (r - l > limit) { // l, r 是T，最小化的目标
        double T = (l + r) / 2;
        bool ok = true;
        double curxL = 0;
        double curxR = 0;
        bool first = true;
        for (auto &it : v) {
            double xl = it.first - (T - it.second);
            double xr = it.first + (T - it.second);
            if (first) {
                first = false;
                curxL = xl;
                curxR = xr;
            } else {
                curxL = max(curxL, xl);
                curxR = min(curxR, xr);
                if (curxL > curxR) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            // 更新ans
            ans = curxL;
            r = T - limit;
        } else {
            l = T + limit;
        }
    }

    cout << setprecision(8) << ans << endl;
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