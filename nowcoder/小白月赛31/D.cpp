#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

/*
x == y
x ^ y = 0
| x - y | = 0

x != y
x ^ y == 1
|x - y| != diff != 0

diff == 1 ?
yes:
    1 ^ 1 = 0
    1 - 1 = 0

no:
    1 ^ diff = 1
    | diff - 1 | = diff
*/
void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    LL h = y2 - y1 + 1;
    LL w = x2 - x1 + 1;
    cout << h *  w << endl;
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
