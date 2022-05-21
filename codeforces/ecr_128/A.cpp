#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    int l1, r1;
    int l2, r2;
    cin >> l1 >> r1;
    cin >> l2 >> r2;
    int l = max(l1, l2);
    int r = min(r1, r2);
    if (l <= r) {
        // 相交
        cout << l << endl;
    } else {
        // 包含
        if ((l == l1 && r == r1)) {
            cout << l << endl;
        } else if ((l == l2 && r == r2)) {
            cout << l << endl;
        } else {
            // 相离
            cout << l1 + l2 << endl;
        }

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
