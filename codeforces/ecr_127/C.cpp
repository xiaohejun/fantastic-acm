#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
LL a[MAX_N];
LL sum[MAX_N];

void solve()
{
    LL n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i <= n; ++i) {
        sum[i] = a[i] + sum[i - 1];
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (sum[i] > x) {
            continue;
        }
        LL k = (x - sum[i]) / i + 1LL;
        if (k > 0) {
            ans += k;
        }
    }
    cout << ans << endl;
}

/*
sum[i] + day <= x

x - sum[i] >= day

1,2,2 -> 1,3,5

        sum[i] + day * i <= x
        day <= (x - sum[i]) / i

        x = 17
        sum[i] = 7


*/

/*

sum[i]

*/

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