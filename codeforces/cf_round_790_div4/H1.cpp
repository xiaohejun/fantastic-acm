#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 1e4+100;
int a[MAX_N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[j] >= a[i]) {
                ++ans;
            }
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
