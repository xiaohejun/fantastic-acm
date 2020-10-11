#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a[2];
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x < 0) {
                a[0].push_back(x);
            }
            if (x > 0) {
                a[1].push_back(x);
            }
        }
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        int lzC = a[0].size();
        int btC = a[1].size();
        int eqC = n - lzC - btC;
        bool can = (lzC >= 0 && btC >= 5) || (lzC >= 2 && btC >= 3) || (lzC >= 4 && btC >= 1);
        LL ans = -1e18;
        if (can) {
            int cnt[3] = {0, 2, 4};
            for (int i = 0; i < 3; ++i) {
                if (lzC >= cnt[i] && btC >= 5 - cnt[i]) {
                    LL tmp = 1LL;
                    for (int k = 0; k < cnt[i]; ++k) {
                        tmp *= a[0][k];
                    }
                    for (int k = btC - 1; k >= btC - (5 - cnt[i]); --k) {
                        tmp *= a[1][k];
                    }
                    ans = max(ans, tmp);
                }
            }            
        } else {
            if (eqC) {
                ans = 0;
            } else {
                for (int i = 0; i <= 5; ++i) {
                    if (lzC >= i && btC >= 5 - i) {
                        LL tmp = 1LL;
                        for (int k = lzC - 1; k >= lzC - i; --k) {
                            tmp *= a[0][k];
                        }
                        for (int k = 0; k < 5 - i; ++k) {
                            tmp *= a[1][k];
                        }
                        ans = max(ans, tmp);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
