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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // 
    int ans = a[n - 1] - a[0];
    int lstDiff = ans;
    for (int i = 0, j = n - 1; i <= j; ++i, --j) {
        if (a[i] != a[j]) {
            if (a[i] < a[j]) {
                int diff = a[j] - a[i];
                if (diff ) {
                    ans = -1;
                    break;
                }
            } else { // a[i] > a[j]，肯定不行
                ans = -1;
                break;
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
