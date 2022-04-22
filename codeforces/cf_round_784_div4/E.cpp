#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 1e5+10;
char s[MAX_N][5];
LL f[26][26];

#define IDX(a) (((a) - 'a'))

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            f[IDX(s[i][0])][IDX(s[i][1])]++;
        }
        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            LL sum1 = 0, sum2 = 0;
            for (int j = IDX('a'); j <= IDX('k'); ++j) {
                if (j != IDX(s[i][0])) {
                    sum1 += f[j][IDX(s[i][1])];
                }
                if (j != IDX(s[i][1])) {
                    sum2 += f[IDX(s[i][0])][j];
                }
            }
            // cout << s[i] << endl;
            // cout << sum1 << " " << sum2 << endl;
            // if (IDX(s[i][0]) == IDX(s[i][1])) {
            //     sum /= 2;
            // }
            ans += (sum1 + sum2);
        }
        cout << ans / 2 << endl;
    }   
    return 0;
}
