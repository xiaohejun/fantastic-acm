#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    LL x, y;
    int t;
    cin >> t;
    int idx = 0;
    while (t--) {
        cin >> x >> y;
        cout << "Case " << ++idx << ": " << x / __gcd(x, y) * y << endl;
    }
    return 0;
}
