#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 35;
int a[MAX_N];

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            l = i;
        }
    }
    int r = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            r = i;
        }
    }
    cout << r - l + 1 << endl;
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
/*
1?1??0?0


*/
