#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    vector<bool> ok(n, true);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] >= n) {
            ok[i] = false;
        }
        if (i < b[i] && n - i - 1 > b[i]) {
            ok[i] = false;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (ok[i]) {
            cout << i << " " << b[i] << endl;
        }
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


/*


 
7 8 4 3 1 2 6 5

*/