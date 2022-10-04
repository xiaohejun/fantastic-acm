#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += (a[i] - 1) / (2 * a[0] - 1);
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
