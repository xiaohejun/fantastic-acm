#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0;
    for (int x : s) {
        if (x == '0') {
            ++cnt0;
        }
    }
    if (n & 1) {
        // n 是奇，必定是奇+偶，有偶必行
        cout << "YES" << endl;
    } else {
        if ((cnt0 & 1) == 0) { // n是偶，0是偶数必行
            cout << "YES" << endl;
            return;
        }
        // 0奇 + 1奇
        cout << "NO" << endl;
    }
}

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
