#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
LL n, m, k;
int T;

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &m, &k);
        // t表示一份k装多少个m
        LL t = k >> 1;
        LL a = m / t;
        if (k&1) {
            n -= min(a, n);
        }
        bool f = false;
        LL rem = m - a * t;
        if (rem) {
            ++a;
            f = true;
        }
        rem = k - rem * 2;
        n -= min(rem, n);
        if (n) {
            printf("%lld\n", n / k + a);
        } else {
            printf("%lld\n", a - f);
        }
    }
    return 0;
}

/*
n 1
m 2
> k
<= k的量
(n + 2*m) / k 上取整

n=14
m=5   2*5 = 10
k=14
离k最近的组合

t = [2*m / k]
*/