#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<LL> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
         for (int i = 1; i <= k; ++i) {
            v[0] += v[i];
            v[i] = 0;
        }
        LL mn = v[0];
        for (int i = 1; i < n; ++i) {
            mn = min(mn, v[i]);
        }
        cout << v[0] - mn << endl;
    }
    return 0;
}
