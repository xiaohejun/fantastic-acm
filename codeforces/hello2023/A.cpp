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
    string s;
    cin >> s;
    bool same = true;
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (s[0] != s[i]) {
            same = false;
        }
        if (s[i] != s[i - 1] && s[i] == 'R' && s[i - 1] == 'L') {
            idx = i;
            break;
        }
    }
    if (same) {
        cout << -1 << endl;
    } else {
        cout << idx << endl;
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
