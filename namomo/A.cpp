#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

typedef long long LL;
const LL MOD = 1e9+7;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<LL> v(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> v[i];
    }    
    sort(v.begin(), v.end());
    LL ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = ans * (v[i] + v[2*n - 1 - i]) % MOD; 
    }
    cout << ans << endl;
    return 0;
}
