#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 2e5+100;
const LL INF = 1e18;
int n;
int a[MAX_N], b[MAX_N];
LL dp[MAX_N][2];

inline void change(LL &x, LL y){
    x = min(x, y);
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i){
        scanf("%d%d", &a[i], &b[i]);
    }
    dp[0][0] = 0;
    dp[0][1] = b[0];
    for(int i = 1; i < n; ++i){
        dp[i][0] =  INF;
        dp[i][1] = INF;
        if(a[i] != a[i-1]){
            change(dp[i][0], dp[i-1][0]);
        }
        if(a[i] != a[i-1]+1){
            change(dp[i][0], dp[i-1][1]);
        }
        if(a[i]+1 != a[i-1]){
            change(dp[i][1], dp[i-1][0]+b[i]);
        }
        if(a[i]+1 != a[i-1]+1){
            change(dp[i][1], dp[i-1][1]+b[i]);
        }
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
    return 0;
}

/*
dp[i][0] 表示不+1最小花费
dp[i][1] 表示+1最小花费

dp[1][0] = 0
dp[1][1] = 1

*/
