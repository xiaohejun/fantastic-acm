#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    unordered_map<int, char> mp;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        dbg(a[i])
        if (mp.find(a[i]) != mp.end()) {
            dbg(a[i])
            dbg(c)
            dbg(mp[a[i]])
            if (mp[a[i]] != c) {
                ok = false;
                break;
            }
        } else {
            mp[a[i]] = c;
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
