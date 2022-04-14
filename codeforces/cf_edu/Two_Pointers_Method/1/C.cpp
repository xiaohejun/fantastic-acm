#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    // freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    LL ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            ++j;
        } else if (a[i] < b[j]) {
            ++i;
        } else { // equal
            int cur = a[i];
            LL cntN = 0;
            while (i < n && a[i] == cur) {
                cntN++;
                ++i;
            }
            LL cntM = 0;
            while (j < m && b[j] == cur) {
                ++cntM;
                ++j;
            }
            ans += cntN * cntM;
        }
    }
    cout << ans << endl;
    return 0;
}
