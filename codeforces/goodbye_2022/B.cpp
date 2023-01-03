#include <bits/stdc++.h>
using namespace std;

// 类型定义
typedef long long ll;

#ifndef ONLINE_JUDGE
    #include "../../algo/debug.h"
#else
    #define dbg(x...)
#endif
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int cost(const vector<int> &a, int k)
{
    
}

void findMinNK(int n, int k) {
    vector<int> a(n);
    int idx = 0;
    generate(a.begin(), a.end(), [&]() { return ++idx; });
    do {
                 
    } while (next_permutation(a.begin(), a.end()));
}

void solve()
{
    int n, k;
    cin >> n >> k;
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
