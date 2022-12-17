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
    int n, q;
    cin >> n >> q;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            LL sum = 0;
            LL xorSum = 0;
            for (int j = i; j < i + len; ++j) {
                sum += a[j];
                xorSum ^= a[j];
            }
            dbg(len, i, i + len - 1, sum, xorSum, (sum - xorSum))
        }
    }
    dbg((32 ^ 32 ^ 32 ^ 10))
    dbg((32 + 32 + 32 + 10))
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
