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
    int h = (n + 1) / 2;

    // if (n == 3) {
    //     cout << "1 2 3" << endl;
    //     return;
    // } else if (n == 4) {
    //     cout << "2 4 1 3" << endl;
    //     return;
    // }
    if (n & 1) {
        for (int i = 1; i <= h; ++i) {
            cout << i << " ";
            if (h + i <= n) {
                cout << h + i << " ";
            }
        }
        cout << endl;
    } else {
        for (int i = 1; i <= h; ++i) {
            if (h + i <= n) {
                cout << h + i << " ";
            }
            cout << i << " ";
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
