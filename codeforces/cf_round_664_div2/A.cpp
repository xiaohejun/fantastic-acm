#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a[4];
        int tmp = 0;
        for (int i = 0; i < 4; ++i) {
            cin >> a[i];
            tmp += a[i] & 1;
        }
        bool ok = false;
        if (a[0] == 0 || a[1] == 0 || a[2] == 0) {
            ok = tmp <= 1;
        } else { // 前三个非0
            // 不做
            ok = tmp <= 1;
            // 做一次
            if (!ok) {
                ok = (4 - tmp) <= 1;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
