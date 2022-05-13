#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 250;
int a[MAX_N][MAX_N];
LL sum1[MAX_N][MAX_N];
LL sum2[MAX_N][MAX_N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int ci = i;
        int cj = 0;
        LL ret = 0;
        while (ci < n && cj < m) {
            ret += a[ci][cj];
            ++ci;
            ++cj;
        }

        ci = i;
        cj = 0;
        while (ci < n && cj < m) {
            sum1[ci][cj] = ret;
            ++ci;
            ++cj;
        }
    }

    for (int j = 0; j < m; ++j) {
        int ci = 0;
        int cj = j;
        LL ret = 0;
        while (ci < n && cj < m) {
            ret += a[ci][cj];
            ++ci;
            ++cj;
        }

        ci = 0;
        cj = j;
        while (ci < n && cj < m) {
            sum1[ci][cj] = ret;
            ++ci;
            ++cj;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        int ci = i;
        int cj = 0;
        LL ret = 0;
        while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
            ret += a[ci][cj];
            --ci;
            ++cj;
        }

        ci = i;
        cj = 0;
        while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
            sum2[ci][cj] = ret;
            --ci;
            ++cj;
        }
    }

    for (int j = m - 1; j >= 0; --j) {
        int ci = n - 1;
        int cj = j;
        LL ret = 0;
        while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
            ret += a[ci][cj];
            --ci;
            ++cj;
        }

        ci = n - 1;
        cj = j;
        while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
            sum2[ci][cj] = ret;
            --ci;
            ++cj;
        }
    }

    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, sum1[i][j] + sum2[i][j] - a[i][j]);
            // cout << sum1[i][j] << "," << sum2[i][j] << "," << a[i][j] << " ";
        }
        // cout << endl;
    }
    cout << ans << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
