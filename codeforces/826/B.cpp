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
    if (n == 3) {
        cout << "-1" << endl;
        return;
    }
    int x = n / 2;
    for (int i = x + 1; i <= n; ++i) {
        cout << i << " ";
    }
    for (int i = 1; i <= x; ++i) {
        cout << i << " ";
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
