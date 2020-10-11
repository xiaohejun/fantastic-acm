#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 1 << 20;
int n, m;
int n_;
LL a[MAX_N];

void change(int i, int v) {
    i += n_ - 1;
    v -= a[i];
    a[i] += v;
    while (i) {
        i = (i - 1) >> 1;
        a[i] += v;
    }
}


LL sum(int l, int r, int lx, int rx, int idx) {
    int l_ = max(l, lx);
    int r_ = min(r, rx);
    LL ans = 0;
    if (l_ < r_) {
        if (l <= lx && rx <= r) {
            ans += a[idx];
        } else {
            int mid = (lx + rx) >> 1;
            ans += sum(l, r, lx, mid, (idx << 1) + 1) + sum(l, r, mid, rx, (idx << 1) + 2);
        }
    }
    return ans;
}

int main(){
    //freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    n_ = 1;
    while (n_ < n) {
        n_ <<= 1;
    }
    int v, l, r;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        change(i, v);
    }
    for (int i = 0; i < m; ++i) {
        cin >> v >> l >> r;
        if (v == 1) {
            change(l, r);
        } else if (v == 2) {
            cout << sum(l, r, 0, n_, 0) << endl;
        }
    }
    return 0;
}
