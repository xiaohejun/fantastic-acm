#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MOD = 1e9 + 7;
const int MAX_N = 4e4+10;
const int MAX_M = 510;
int dp[MAX_N][MAX_M];
const int MAX_T = 1e4 + 10;
int n[MAX_T];

void dfs(vector<int> &ret, vector<int> &num, int cur, int n, int max)
{
    if (cur > ((n + 1) / 2 - 1)) {
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp = tmp * 10 + num[i];
        }
        if (tmp > max) {
            return;
        }
        ret.push_back(tmp);
        return;
    }
    int s = 0;
    if (cur == 0) {
        s = 1;
    }
    for (; s <= 9; ++s) {
        num[cur] = s;
        num[n - 1 - cur] = s;
        dfs(ret, num, cur + 1, n, max);
    }
}

void getPNum(vector<int> &pnum, int n, int max)
{
    vector<int> num(n, 0);
    dfs(pnum, num, 0, n, max);
}

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int mx = 0;
    for (int i = 0; i < t; ++i) {
        cin >> n[i];
        mx = max(mx, n[i]);
    }
    vector<int> pnum;
    pnum.push_back(0); // 从1开始，默认搞个0
    for (int i = 1; i <= 5; ++i) {
        getPNum(pnum, i, mx);
    }
    // dbg(mx)
    // dbg(pnum.size())

    int m = pnum.size();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int j = 1; j < m; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= mx; ++i) {
        for (int j = 1; j < m; ++j) {
            if (pnum[j] <= i) {
                dp[i][j] = dp[i - pnum[j]][j];
            }
            dp[i][j] = (dp[i][j - 1] + 0LL + dp[i][j]) % MOD;
        }
    }

    // dbg(pnum.size())
    // for (int j = 1; j <= 10; ++j) {
    //     cout << pnum[j] << " ";
    // }
    // dbg("")
    // for (int i = 1; i <= 5; ++i) {
    //     for (int j = 1; j < m; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < t; ++i) {
        cout << dp[n[i]][m - 1] << endl;
    }
    return 0;
}

/*
dp[1][1] = 1
dp[2][1] = 1(1+1),
dp[3][1] = 2(1+1+1, 2+1)
dp[4][1] = (1+1+1+1, 2+1+1, 3+1)

1位
1 2 ... 9 = 9个

2位
11 22 33 44 .. 99 = 9个

3位
101 111 121 .... 191
202 .....        292
................... = 9 * 9 = 81个

4位 = 81
1001

5位

1—— —— —— 1 9 * 9 * 10 = 810

1000个数字划分

n * 1000 = 1e7
dp[i][j] 数字i最后一个是num[j]的方案数字

dp[i][j] = \sum dp[i - num[j]][1...j] + 1
*/