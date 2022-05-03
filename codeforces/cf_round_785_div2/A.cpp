#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if ((n&1) == 0) {
        int ans = 0;
        for (int c : s) {
            ans += ((c - 'a') + 1);
        }
        cout << "Alice " << ans << endl;
    } else {
        // 奇数个，只能拿偶数个
        int ansAL = 0;
        for (int i = 0; i < n - 1; ++i) {
            ansAL += ((s[i] - 'a') + 1);
        }
        int ansBL = (s[n - 1] - 'a') + 1;

        int ansAR = 0;
        for (int i = 1; i < n; ++i) {
            ansAR += ((s[i] - 'a') + 1);
        }
        int ansBR = (s[0] - 'a') + 1;

        int ansA = 0;
        int ansB = 0;
        if (ansAL > ansAR) {
            ansA = ansAL;
            ansB = ansBL;
        } else {
            ansA = ansAR;
            ansB = ansBR;
        }
        if (ansA > ansB) {
            cout << "Alice " << ansA - ansB << endl;
        } else {
            cout << "Bob " << ansB - ansA << endl;
        }
    }
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
