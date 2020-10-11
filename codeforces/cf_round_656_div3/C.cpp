#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> b(n);
    for (int i = 1; i < n; ++i) {
        int x = a[i] - a[i - 1];
        b[i] = x <= 0 ? (x == 0 ? 0 : -1) : 1;
    }
    int idx = n - 1;
    int ans = 0;
    int x;
    while(idx >= 1) {
        x = b[idx];
        if (x == 0) {
            while (idx >= 1 && (b[idx] == x || b[idx] == 0)) {
                ++ans;
                --idx;
            }
        }
        break;
    }
    while (idx >= 1) {
        x = b[idx];
        while (idx >= 1 && (b[idx] == x || b[idx] == 0)) {
            ++ans;
            --idx;
        }    
        break;
    }
    if (x == -1) {
        while (idx >= 1) {
            x = b[idx];
            while (idx >= 1 && (b[idx] == x || b[idx] == 0)) {
                ++ans;
                --idx;
            }    
            break;
        }
    }
    cout << n - ans - 1 << endl;
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
