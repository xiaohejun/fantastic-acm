#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    bool ok = true;
    if (x >= a) {
        x -= a;
    } else {
        x = 0;
    }
    if (y >= b) {
        y -= b;
    } else {
        y = 0;
    }
    if (x + y > c) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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
