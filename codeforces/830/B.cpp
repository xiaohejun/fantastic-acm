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
    int idx = s.find('1');
    if (idx == string::npos) {
        cout << "0" << endl;
        return;
    }
    int ans = 0;
    for (int i = idx; i < n;) {
        char c = s[i];
        while (i < n && s[i] == c) {
            ++i;
        }
        ++ans;
    }
    cout << ans - 1 << endl;
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
