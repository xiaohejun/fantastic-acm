#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

char s[10][10];
int n, m;

bool isOk(int ci, int cj)
{
    dbg(ci)
    dbg(cj)
    dbg("--")
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'R') {
                if (i - ci < 0 || j - cj < 0) {
                    dbg(ci)
                    dbg(cj)
                    return false;
                }
            }
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        dbg(s[i])
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'R' && isOk(i, j)) {
                dbg(i)
                dbg(j)
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
