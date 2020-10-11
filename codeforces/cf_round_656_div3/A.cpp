#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int a[3];
    while (t--) {
        for (int i = 0; i < 3; ++i) cin >> a[i];
        sort(a, a + 3);
        if (a[2] == a[1]) {
            cout << "YES" << endl;
            if (a[1] == a[0]) {
                cout << a[0] << " " << a[1] << " " << a[2] << endl;
            } else {
                cout << a[0] << " " << a[0] << " " << a[2] << endl;
            }
        } else cout << "NO" << endl;
    }
    return 0;
}
