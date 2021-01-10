#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

/*
a : 100110
011001

a: 
10
0

x = 3
*/
void solve()
{
    int a, x;
    cin >> a >> x;
    vector<int> bit;
    for (int i = 0; i < 32; ++i) {
        if ((a >> i) & 1) {
            bit.push_back(1);
        } else {
            bit.push_back(0);
        }
    }
    int cnt = 0;
    int tmp = 0;
    for (int i = 0; i < 32; ++i) {
        if (bit[i]) {
            cnt += tmp;
            tmp = 0;
        } else {
            ++tmp;
        }
    }
    dbg(cnt)
    int ret = 1;
    for (int i = 1; i <= cnt; ++i) {
        ret *= 2;
    }
    cout << ret - 1 << endl;
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
