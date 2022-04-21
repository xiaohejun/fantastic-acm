#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

LL count(int idx, vector<LL> &a)
{
    int n = a.size();
    LL mv = 0;
    if (idx + 1 < n) {
        LL cur = a[idx + 1];
        mv++;
        for (int i = idx + 2; i < n; ++i) {
            if (cur < a[i]) {
                cur = a[i];
                mv++;
            } else { // cur >= a[i]
                LL k = cur / a[i];
                if (k * a[i] <= cur) {
                    ++k;
                }
                cur = k * a[i];
                mv += k;
            }
        }
    }
    if (idx - 1 >= 0) {
        LL cur = a[idx - 1];
        mv++;
        for (int i = idx - 2; i >= 0; --i) {
            if (cur < a[i]) {
                cur = a[i];
                mv++;
            } else { // cur > a[i]
                LL k = cur / a[i];
                if (k * a[i] <= cur) {
                    ++k;
                }
                cur = k * a[i];
                mv += k;
            }
        }
    }
    return mv;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ans = count(i, a);
        } else {
            ans = min(ans, count(i, a));
        }
    }
    cout << ans << endl;
    return 0;
}

/*
2 <= n <= 5000

a[1] ... a[i] .. a[n]

ki * a[i]

sum{ki} min
(+-)k[i-1] * a[i - 1] < k[i] * a[i]


1 8

8
1 8 2 7 3 6 4 5
9 1 5 2 5 3 5 5
9 8 10 14 15 18 20 25

16

1 2 1 2 1 2 1
    1 2 3 4 5
    1 1 3 2 5
*/