#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

#define MAX 15
LL f[MAX][MAX];

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int j = 0; j <= k; ++j) {
        f[1][j] = 1; 
    }
    for (int i = 2; i <= n; ++i) { // n个数字
        for (int j = 0; j <= k; ++j) { // 组成k
            f[i][j] = f[i - 1][j];
            for (int l = 1; l <= j; ++l) { // 范围就是k
                f[i][j] += f[i - 1][j - l];
            }
        }        
    } 
    cout << f[n][k] << endl;
    return 0;
}

/*
2 3

0 3
1 2
2 1
f[i][j] // 前i个凑j的方案

*/