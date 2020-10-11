#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "[" << __func__ << ":" << __LINE__ << "] : " << #x"=" << x << endl;

int main(){
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> has(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x < n) {
                has[x]++;
            }
        }
        int ans = 0;
        int up = 2;
        int i = 0;
        while (i <= n) {
            if (has[i] >= up) {
                ++i;
            } else {
                if (up == 2) {
                    if (has[i] == 0) {
                        ans = 2 * i;
                        break;
                    } else {
                        ans = i;
                        up = 1;
                        ++i;
                    }
                } else {
                    ans += i;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
