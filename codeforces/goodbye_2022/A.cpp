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
    int32_t n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int64_t> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int64_t ans = 0;
    auto aiter = a.begin();
    auto biter = b.begin();
    for (size_t i = 0; i < n; ++i) {
        if (aiter != a.end() && biter != b.end()) {
            if (*aiter > *biter) {
                ans += *aiter;
                ++aiter;
            } else {
                ans += *biter;
                ++biter;
            }
        } else if (aiter != a.end()) {
            ans += *aiter;
            ++aiter;
        } else {
            ans += *biter;
            ++biter;
        }
    }
    if (biter == b.begin()) {
        ans -= a.back();
        ans += *b.begin();
    }
    cout << ans << endl;
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
