#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
 
typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
 
#define MAX_N 110
#define MAX_X 10010
 
int dp[MAX_N][MAX_X] = {0};
char ans[MAX_X] = {0};
 
int main(){
    // freopen("in.txt", "r", stdin);
    int n;
    int x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (dp[i][j] == 1) {
                dp[i + 1][min(j + v[i].first, x + 1)] = 1;
                dp[i + 1][min(j + v[i].second, x + 1)] = 1;
            }
        }
    }
 
    bool ok = dp[n][x];
    cout << (ok ? "Yes" : "No") << endl;
 
    if (ok) {
        int s = x;
        for (int i = n; i > 0; --i) {
            if (dp[i - 1][s - v[i - 1].first]) {
                ans[i] = 'H';
                s -= v[i - 1].first;
                continue;
            }
            if (dp[i - 1][s - v[i - 1].second]) {
                ans[i] = 'T';
                s -= v[i - 1].second;
                continue;
            }
        }
        assert(s == 0);
        cout << (ans+1) << endl;
    }
    return 0;
}