#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    string t = "";
    int first = 0;
    int end = n - 1;
    for (int i = 0; i < n; ++i) {
        if ((i&1) == 0) { // A
            if (s[first] == '1') {
                t = t + '1';
            } else {
                t = '0' + t;
            }
            ++first;
        } else { // B
            if (s[end] == '1') {
                t = '1' + t;
            } else {
                t = t + '0';
            }
            --end;
        }
    }
    cout << t << endl;
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
