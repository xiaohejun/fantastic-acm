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
    int a = 10;
    long b = 20;
    long long c = 30;
    unsigned int d = 50;
    dbg(a, b, c, d)

    unsigned long e = 60;
    unsigned long long f = 70;
    float g = 70.1;
    double h = 77.7777777;
    long double i = 79.90909090;
    dbg(e, f, g, h, i)

    char j = 'j';
    const char *k = "kkkkkk";
    string l = "this is a string";
    bool m = false;
    dbg(j, k, l, m)

    pair<int, char> p(1, 'a');
    dbg(p)

    vector<int> vecInt = {1, 2, 3, 4, 5, 6};
    dbg(vecInt)
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
