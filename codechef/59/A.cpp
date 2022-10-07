#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string t = "aeiou";
    bool ok = false;
    for (int i = 0; i < n && !ok; ++i) {
        int cnt = 0;
        while (i < n && t.find(s[i]) != string::npos) {
            ++cnt;
            ++i;
        }
        if (cnt > 2) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Happy" : "Sad") << endl;
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
