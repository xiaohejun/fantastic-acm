#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
int a[MAX_N];

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = -1;
        for (int i = 0; i < n && ans == -1;) {
            int cur = a[i];
            int cnt = 0;
            while (i < n && a[i] == cur) {
                ++cnt;
                ++i;
            }
            if (cnt >= 3) {
                ans = cur;
                break;
            }
        }
        cout << ans << endl;
    }   
    return 0;
}
