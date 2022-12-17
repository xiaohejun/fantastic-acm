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

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i == 1) {
            k = a[i];
        } else {
            k = gcd(k, a[i]);
        }
    }

    int ans = n;
    int curI = n;
    for (int i = n; i >= 1; --i) {
        if (gcd(k, i) == 1) {
            curI = i;
            ans = n - i + 1;
            break;
        }
    }

    for (int i = n; i >= curI + 1; --i) {
        int curK = k;
        int ret = 0;
        
        while ((curK % i) == 0 && curK > 1) {
            ret += n - i + 1;
            has[i] = true;
            curK /= i;
            if (curK <= curI) {

            }
        }
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
