#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 55;
int a[MAX_N];

void solve()
{
    int n;
    cin >> n;
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(a[i], mn);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (a[i] - mn);
    }
    cout << sum << endl;
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
