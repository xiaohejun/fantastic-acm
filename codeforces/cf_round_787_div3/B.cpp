#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 35;
int a[MAX_N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        while (a[i] >= a[i + 1] && a[i] != 0) {
            a[i] /= 2;
            ++ans;
        }
        if (a[i] >= a[i + 1]) {
            ans = -1;
            break;
        }
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
