#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const ll p = 911451407;

const int maxn = 2e6 + 10;
ll fac[maxn];//阶乘打表

void init(ll p)//此处的p应该小于1e5，这样Lucas定理才适用
{
    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
        fac[i] = fac[i - 1] * i % p;
}

ll pow(ll a, ll b, ll m)
{
    ll ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)ans = (ans % m) * (a % m) % m;
        b /= 2;
        a = (a % m) * (a % m) % m;
    }
    ans %= m;
    return ans;
}

ll inv(ll x, ll p)//x关于p的逆元，p为素数
{
    return pow(x, p - 2, p);
}

ll C(ll n, ll m, ll p)//组合数C(n, m) % p
{
    if(m > n)return 0;
    return fac[n] * inv(fac[m] * fac[n - m], p) % p;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int t;
    init(p);
    scanf("%d", &t);
    while(t--){
        ll l, x;
        scanf("%lld%lld", &l, &x);
        printf("%lld\n", C(l + x - 2, x - 1, p));
    }
    return 0;
}

/*
dp[i][j] 表示长度是i，最后一个数字是j的方案
dp[1][j] = 1  (j任意)
dp[i][j] = \sum{dp[i-1][<= j]}
(i, j)

dp[i][j] = dp[i-1][j] + dp[i][j-1]
C(i, j)
1
2 1
3 3 1


dp[6][1] = C(5, 0)
dp[5][2] = C(5, 1)
dp[4][3] = C(5, 2)
dp[3][4] = C(5, 3)
dp[2][5] = C(5, 4)
dp[1][6] = C(5, 5)

dp[7][1] = C(6, 0)
dp[6][2] = C(6, 1)
dp[5][3] = C(6, 2)
dp[4][4] = C(6, 3)
dp[3][5] = C(6, 4)
dp[2][6] = C(6, 5)
dp[1][7] = C(6, 6)

dp[8][1] = C(7, 0)

l, x
n, m

m = x-1

x - 1
y + 1
第0行 (1, 1) = 2
第一行(2, 1) (1, 2) = 3
第二行(3, 1) (2, 2) (1, 3) = 4

*/