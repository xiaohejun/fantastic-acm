#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += (s[i] - '0');
    }
    for (int i = 3; i < 6; ++i) {
        sum -= (s[i] - '0');
    }
    cout << ((sum == 0) ? "YES" : "NO") << endl;
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
