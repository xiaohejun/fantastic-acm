#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    for (int i = 0; i < n;) {
        char c = s[i];
        int cnt = 0;
        while (i < n && c == s[i]) {
            ++cnt;
            ++i;
        }
        if (cnt < 2) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
    // 2 + 2 + 3

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
