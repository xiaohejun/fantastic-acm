#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x) ;
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    int mn = 2e8 + 10;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, x[i] - t[i]);
        mx = max(mx, x[i] + t[i]);
    }

    dbg(mn)
    dbg(mx)
    cout << (mx + mn) / 2;
    if ((mx + mn) & 1) {
        cout << ".5";
    }
    cout << endl;
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