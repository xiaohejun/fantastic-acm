#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 100+10;
int a[MAX_N];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < n;) {
        int cnt = 0;
        char c = s[i];
        while (i < n && c == s[i]) {
            ++cnt;
            ++i;
        }
        v.push_back(cnt);
    }
    int m = v.size();
    int ans = 0;
    for (int i = 0; i < m - 1; ++i) {
        if (v[i] & 1) {
            --v[i];
            ++v[i + 1];
            ++ans;
        }
    }
    for (int x : v) {
        cout << x << " ";

    }
    cout << endl;
    cout << ans << endl;
}

/*
11 10 01 10 00

10 01 10 00
*/

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
