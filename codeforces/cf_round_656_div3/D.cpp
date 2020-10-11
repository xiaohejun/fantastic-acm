#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

string s;

int f(int l, int r, char c) {
    if (r - l == 1) {
        return c != s[l];
    }
    int mid = (l + r) >> 1;
    int cnt1 = 0;
    for (int i = l; i < mid; ++i) {
        cnt1 += s[i] != c;
    }
    int cnt2 = 0;
    for (int i = mid; i < r; ++i) {
        cnt2 += s[i] != c;
    }
    return min(cnt1 + f(mid, r, c + 1), cnt2 + f(l, mid, c + 1));
}

void solve() {
    int n;
    cin >> n;
    cin >> s;
    cout << f(0, n, 'a') << endl;
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
