#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

bool hasSame(string &a, string &b)
{
    vector<bool> has(26, false);
    for (char c : a) {
        has[c - 'a'] = true;
    } 
    for (char c : b) {
        if (has[c - 'a']) {
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int l = 0;
    int r = n - 1;
    bool ok = true;
    while (l <= r) {
        if (!hasSame(v[l], v[r])) {
            ok = false;
            break;
        }
        ++l;
        --r;
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;;
    while (t--) {
        solve();
    }
    return 0;
}
