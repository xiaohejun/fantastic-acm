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
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        cur += c - '0';
        if (i > 0) {
            if (cur > 0) {
                cout << "-";
                cur -= 2 * (c - '0');
            } else {
                cout << "+";
            }
        }
    }
    cout << endl;
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
