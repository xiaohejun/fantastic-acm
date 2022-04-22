#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 50+10;
int a[MAX_N];

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (((i & 1) == 1 && i >= 3) || (((i & 1) == 0) && i >= 2)) {
                if ((a[i] & 1) != (a[i - 2] & 1)) {
                    ok = false;
                }   
            }
        }
        cout << (ok ? "YES" : "NO" ) << endl;
    }   
    return 0;
}
