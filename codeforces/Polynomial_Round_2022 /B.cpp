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

#include "algo/algo.h"


void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    dbg(n, m, k)
    int kk = n / k;
    if (kk * k < n) {
        kk++;
    }
    dbg(kk)
    bool ok = true;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (x > kk) {
            ok = false;
        }
    }
    dbg(ok)
    cout << (ok ? "YES" : "NO") << endl; 
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
