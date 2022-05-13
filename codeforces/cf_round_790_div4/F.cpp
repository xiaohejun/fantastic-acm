#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    map<int, int> cnt;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int curL = 0;
    int curR = -1;
    int l = 0;
    int r = -1;
    for (auto &it : cnt) {
        if (it.second < k) {
            continue;
        } else {
            if (l == 0) {
                l = it.first;
                r = it.first;
            } else {
                // l != 0
                if (it.first == r + 1) {
                    r = it.first;
                } else {
                    if ((r - l) > (curR - curL)) {
                        curL = l;
                        curR = r;
                    }
                    l = it.first;
                    r = it.first;
                }
            }
        }
    }
    if (l != 0 && ((r - l) > (curR - curL))) {
        curL = l;
        curR = r;
    }
    if (curR - curL == -1) {
        cout << -1 << endl;
    } else {
        cout << curL << " " << curR << endl;
    }
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
