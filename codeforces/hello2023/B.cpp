#include <bits/stdc++.h>
using namespace std;

// 类型定义
typedef long long LL;

#ifndef ONLINE_JUDGE
    #include "../../algo/debug.h"
#else
    #define dbg(x...)
#endif
#define fastio ios::sync_with_stdio(0); cin.tie(0);


void solve()
{
    int n;
    cin >> n;
    if (n&1) {
        if (n == 3) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            int h = n / 2;
            int h1 = h - 1;
            for (int i = 1; i <= n; ++i) {
                if (i&1) {
                    cout << -h1 << " ";
                } else {
                    cout << h << " ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            if (i&1) {
                cout << -1;
            } else {
                cout << 1;
            }
            if (i != n - 1) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    fastio;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
