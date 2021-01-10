#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL INF = 1e18 + 10;
const int IINF = 1e9;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    LL x, y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        cout << -1 << endl;
        return;
    }
    if (x > y) {
        cout << 0 << endl;
        return;
    }
    // x <= y
    if (x == 1 || y == 1) {
        cout << -1 << endl;
        return;
    }
    int k = 0;
    LL now = 1;
    int ans = 0;
    while (true) {
        if (now <= y) {
            ans = k;
        } else {
            break;
        }
        if (now > y / x + 1) {
            break;
        }
        now *= x;
        ++k;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
