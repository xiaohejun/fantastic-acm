#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 2e3+100;
LL f[MAX_N];
int n, k;
LL w1, w2;
const LL INF = 1e18;

LL Min(LL s, int x0, int y0, int x, int y) {
    LL s1 = (x - x0 + y - y0) * w1;
    if (x0 + 1 <= x && y0 + 1 <= y) {
        s1 = min(s1, (x - x0 - 1 + y - y0 - 1) * w1 + w2);
    }
    return s + s1;
}

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> w1 >> w2;
    vector<pair<int, int>> a;
    for (int i = 0; i < k; ++i) {
        f[i] = INF;
        int x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end());
    if (k) {
        int x = a[0].first;
        int y = a[0].second;
        if (x + y == 0) {
            f[0] = 0;
        } else {
            f[0] = (x + y) * w1;
        }
    }
    for (int i = 0; i < k; ++i) {
        int x = a[i].first;
        int y = a[i].second;
        for (int j = 0; j < i; ++j) {
            int x0 = a[j].first;
            int y0 = a[j].second;
            if (x0 <= x && y0 <= y) {
                f[i] = min(f[i], Min(f[j], x0, y0, x, y));                
            }
        }
    }
    LL ans = 2LL * n * w1;
    for (int i = 0; i < k; ++i) {
        ans = min(Min(f[i], a[i].first, a[i].second, n, n), ans);
    }
    cout << ans << endl;
    return 0;
}
