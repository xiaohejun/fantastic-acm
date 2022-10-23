#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x) void(x)
#endif

LL myceil(LL x, LL a)
{
    LL k = x / a;
    if (k * a <= x) {
        ++k;
    }
    return k;
}

void solve()
{
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    
    LL ab = a * b;
    // dbg(ab)
    for (int x = a + 1; x <= c; ++x) {
        LL l = myceil(x, a);
        LL r = (d * x) / ab;
        if (l > r || r < 1) {
            continue;
        }
        LL k = r;
        if ((k * ab) % x != 0) {
            continue;
        }
        LL y = (k * ab) / x;
        if (a < x && x <= c && b < y && y <= d && ((x * y) % ab == 0)) {
            cout << x << " " << y << endl;
            return;
        }
    }

    cout << "-1 -1" << endl;
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

/*
1024 373248
729  730

2048 729
*/