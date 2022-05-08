#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

const int MAX_N = 1e5+10;
char s[MAX_N];
char sc[30];
int n, k;

bool isSc(char c)
{
    for (int i = 0; i < k; ++i) {
        if (c == sc[i]) {
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n >> s;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> sc[i];
    }
    int mx = 0;
    for (int i = 0; i < n;) {
        char cur = s[i];
        dbg(cur)
        int dis = 1;
        ++i;
        while (i < n && !isSc(s[i])) {
            ++dis;
            ++i;
        }
        if (i >= n) {
            dis = 0;
        }
        dbg(dis)
        mx = max(mx, dis);
    }
    cout << mx << endl;
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
