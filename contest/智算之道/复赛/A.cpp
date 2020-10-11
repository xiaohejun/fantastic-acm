#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    LL aa, b;
    cin >> aa >> b;
    LL x = aa;
    LL base = 1;
    if (x) {
        while (x) {
            x /= 10;
            base *= 10;
        }
    } else {
        base = 10;
    }
    int ans = 0;
    for (LL i = 100; i <= 999; ++i) {
        LL tmp = base * i + aa;
        if (tmp % b == 0) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
