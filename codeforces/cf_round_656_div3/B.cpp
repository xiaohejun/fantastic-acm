#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve() {
    int n;
    cin >> n;
    vector<bool> a(n, false);
    vector<int> ans;
    int x;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> x;
        if (!a[x - 1]) {
            ans.push_back(x);
        }
        a[x - 1] = true;
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
