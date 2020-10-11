#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n) dbg(n)
    return 0;
}

/*
特殊情况
没有G  YES

没有B

任意一个G被B围住了 NO


除了(n, m)把所有的.都变成#
如果还有B能到，那就是No
没有B能到，所有G能不能到?

一开始
n*m的复杂度计算哪些点是可以到达终点的

.全部变成#

*/