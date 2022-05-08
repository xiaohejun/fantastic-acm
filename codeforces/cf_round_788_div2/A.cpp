#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

const int MAX_N = 1e5+10;
int a[MAX_N];

void solve()
{
    int n;
    cin >> n;
    int opt = 0;
    int neg = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            ++opt;
        } else {
            ++neg;
        }
    }
    int canSwap = min(opt, neg);
    dbg(canSwap)
    int sw = 0;
    // 前neg全是负的，后opt全是正的
    // 负数
    for (int i = 0; i < neg; ++i) {
        if (a[i] > 0 && canSwap > 0) {
            --canSwap;
            ++sw;
            a[i] = -a[i];
        }
        dbg(a[i])
    }
    // 正数
    for (int i = neg; i < n; ++i) {
        if (a[i] < 0 && sw > 0) {
            --canSwap;
            a[i] = -a[i];
        }
        dbg(a[i])
    }
    bool ok = true;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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
