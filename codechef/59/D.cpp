#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_K = 1e9+10;

LL maxSubSum(vector<LL> &a)
{
    LL ans = 0;

    LL curMx = a[0];
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        curMx = max(a[i], curMx + a[i]);
        ans = max(ans, curMx);
    }

    return ans;
}

void solve()
{
    int n, m;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    LL sum = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (x > 0) {
            sum += x;
        }
    }

    a[n] = sum;
    LL ans = maxSubSum(a);

    if (sum == 0) {
        cout << ans << endl;
        return;
    }

    vector<LL> c(n + 1);
    c[0] = sum;
    for (int i = 1; i <= n; ++i) {
        c[i] = a[i - 1];
    }

    ans = max(ans, maxSubSum(c));

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
