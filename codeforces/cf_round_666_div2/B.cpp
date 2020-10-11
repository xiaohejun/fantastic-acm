#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int up = 1000000;
    sort(a.begin(), a.end());
    LL ans = 1e18;
    for (LL c = 1; c <= up; ++c) {
        LL now = 1;
        LL ret = 0;
        bool ok = true;
        for (int i = 0; i < n && ok; ++i) {
            LL tmp = a[i] - now;
            ret += tmp < 0 ? -tmp : tmp;
            if (now >= now * c || now * c / now != c) {
                ok = false;
            }
            now *= c;
        }
        if (ok) {
            if (ret < ans) {
                ans = ret;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
