#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    int n, m;
    cin >> n >> m;
    // dbg(n)
    // dbg(m)
    int x[] = {1, -1};
    int y[] = {2, -2};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            bool ok = false;
            for (int k = 0; k < 2 && !ok; ++k) {
                for (int l= 0; l < 2 && !ok; ++l) {
                    int ii = i + x[k];
                    int jj = j + y[l];
                    if (1 <= ii && ii <= n && 1 <= jj && jj <= m) {
                        ok = true;
                        break;
                    }

                    ii = i + y[l];
                    jj = j + x[k];
                    if (1 <= ii && ii <= n && 1 <= jj && jj <= m) {
                        ok = true;
                        break;
                    }
                }
            }
            if (!ok) {
                cout << i << " " << j << endl;
                return;
            }
        }
    }

    cout << "1 1" << endl;
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
