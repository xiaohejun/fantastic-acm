#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 110;
bool f[MAX_N][MAX_N];
char s[MAX_N][MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(f, false, sizeof(f));
    f[n - 1][m - 1] = true;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int dir[2][2] = {{0, 1}, {1, 0}};
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            char c = s[i][j];
            if (c == 'R') {
                int x = i + dir[0][0];
                int y = j + dir[0][1];
                if (!(x < n && y < m && f[x][y])) {
                    ++ans;
                }
            } else if (c == 'D') {
                int x = i + dir[1][0];
                int y = j + dir[1][1];
                if (!(x < n && y < m && f[x][y])) {
                    ++ans;
                }
            }
            f[i][j] = true;
        }
    }
    cout << ans << endl;
}

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
