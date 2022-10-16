#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    int i = 0;
    int j = 0;
    int mx = a[n - 1];
    int n1 = 0;
    int n2 = 0;
    for (int x = 1; x <= 2 * n; ++x) {
        if (i < n && a[i] == x) {
            ++i;
        } else {
            b[j++] = x;
            if (x < mx) {
                ++n1;
            } else {
                ++n2;
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i < k; ++i) {
        mx = max(mx, b[i]);
        ans += (mx - b[i]);
    }
    if (n2 == 0) {
        cout << ans << endl;
    } else {
        // n2 > 0
        int curMx = b[n - 1];
        LL ans1 = 0;
        for (int i = 0; i < k - 1; ++i) {
            ans1 += curMx - b[i];
        }
        dbg(ans)
        dbg(ans1)
        cout << max(ans, ans1) << endl;
    }
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
