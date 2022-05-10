#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

using usi = unsigned;

const int MAX_N = 5e3+100;
usi p[MAX_N];
int f[MAX_N][MAX_N];
int g[MAX_N][MAX_N];
int dp[MAX_N];

void init(int n)
{
    n += 10;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            f[i][j] = 0;
            g[i][j] = 0;
            dp[j] = 0;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = f[i][j - 1] + (p[j] > p[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= i; --j) {
            g[i][j] = g[i][j + 1] + (p[i] > p[j]);
        }
    }

    // dbg
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // dbg("---")
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    /*
    - - - - - - - - - - - -
    |       |  
    a      c-1

    - - - - - - - - - - - -
    |         |
    a         c

    dp[i][j - 1] ---> dp[i][j]

    l:多了一个j-1(加上)统计j-1到后面的逆序对，pj-1 > p[j + 1, n]
    r:少了一个j(减去) sumf（j, i, j - 2）
    */

    int ans = 0;
    for (int a = 1; a <= n; ++a) {
        // c = a + 2 至少留一个b的位置
        // c <= n-1 后面至少六一个d的位置
        dp[a + 1] = 0;
        for (int c = a + 2; c <= n - 1; ++c) {
            dp[c] = dp[c - 1];
            // 加上 p[c-1] > p[c+1...n]的个数
            // 减去 p[a+1...c-2] > p[c]的个数
            dp[c] += g[c - 1][c + 1];
            int sum = f[c][c - 2] - f[c][a];
            dp[c] -= sum; 
            if (p[a] < p[c]) {
                ans += dp[c];
            }
        }
    }

    
    cout << ans << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
5 3 6 1 4 2

a < b < c < d

pa < pc

pb > pd

dp[b][d] 表示取b,d时的方案数
dp[b][d] = 

n^2
枚举<b, d>,[1, b) [b+1, d)的顺序对的个数

枚举<a, c> 确保 pa < pc
[a+1, c - 1] [c+1, n] 逆序对个数

5 1 6 2 8 3 4 10 9 7

i < j
dp[i][j] <i + 1, j - 1>, <j + 1, n>的逆序对数
dp[i][i + 1] = 0

dp[i][j] = dp[i][j - 1]

        >

- - - - - - - - - - - -
    |       |  
    a      c-1

- - - - - - - - - - - -
    |         |
    a         c

dp[i][j - 1] ---> dp[i][j]

l:多了一个j-1(加上)统计j-1到后面的逆序对，pj-1 > p[j + 1, n]
r:少了一个j(减去) sumf（j, i, j - 2）

j < i

f[i][j] 表示p[i]的前p[1..j] > p[i]个数

f[i][j] = 
         f[i][j - 1]
         f[i][j - 1]  p[j] > p[i] 

sumf(int i, int l, int r) p[l+1, r] > p[i]的个数
    f[i][r] - f[i][l]

g[i][j]
*/