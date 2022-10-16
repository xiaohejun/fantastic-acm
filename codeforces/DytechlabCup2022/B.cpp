#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

LL get(LL x)
{
    if (x == 0) {
        return 0;
    }

    LL i = sqrt(x);
    dbg(x)
    dbg(sqrt(x))
    dbg(i)
    LL ans = (i - 1) * 3;
    dbg(ans)
    if (i * i <= x) {
        ++ans;
    }

    if (i * i + i <= x) {
        ++ans;
    }

    if (i * i + 2LL * i == x) {
        ++ans;
    }

    dbg(ans)
    return ans;
}

void solve()
{
    LL l, r;
    cin >> l >> r;
    cout << get(r) - get(l - 1) << endl;
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
