#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5 + 10;
int a[MAX_N];
LL sum[MAX_N];

bool cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+1+n, cmp);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
        // dbg(i)
        // dbg(sum[i])
    }
    for (int i = 0; i < q; ++i) {
        LL x;
        cin >> x;
        int l = 1, r = n;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (sum[mid] >= x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
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
