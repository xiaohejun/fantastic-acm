#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
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
    int acnt0 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            ++acnt0;
        }
    }

    vector<int> b(n);
    int bcnt0 = 0;
    int noSame = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == 0) {
            ++bcnt0;
        }
        if (a[i] != b[i]) {
            noSame++;
        }
    }

    int ans = 0;
    if (noSame == 0) {
        ans = 0;
    } else {
        ans = min(abs(acnt0 - bcnt0) + 1, noSame);
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
