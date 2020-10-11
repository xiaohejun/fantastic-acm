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
0 1 2 3 4 5 6 7 8 9
0 1 2 3 0 1 2 3 0 1
复杂度
100 * 200 * 500 = 1e7

0 ... l中 % a = i的个数
l / a + ((l % a) >= i)

l ... r中可以计算出
(x % a) 区间 [0, a-1] 
把x按照模数i分类

x % a -> f1 -> f1 % b -> f2

(x % b) 区间 [0, b-1]
把x按照模数j分类

x % b -> g1 -> g1 % a -> g2

要使f2 != g2
f1 % b != g1 % a

0 1 2 3 ... a-1
0 1 2 3 4 .......b-1

计算相等的个数

f1 % b = g1 % a
f1 % b的范围在[0, b-1]
g1 % a的范围在[0, a-1]

相等的k, k 的 范围[0, min(a-1, b-1)]
f1 
*/
