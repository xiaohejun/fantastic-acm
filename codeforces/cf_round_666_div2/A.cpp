#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void sovle() {
    int n;
    cin >> n;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            cnt[c - 'a']++;
        }
    }
    bool ok = true;
    for (int i = 0; i < 26 && ok; ++i) {
        ok &= (cnt[i] % n == 0);
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sovle();
    }
    return 0;
}
