#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int cnt;
        cin >> cnt;
        int k[3] = {0};
        k[0] = cnt / 3;
        int mod3 = cnt % 3;
        if (mod3 == 2 && k[0]) {
            k[0]--;
            k[1] = 1;
            mod3 = 0;
        }
        if (mod3 == 1 && k[0] >= 2) {
            k[0] -= 2;
            k[2] = 1;
            mod3 = 0;
        }
        if (mod3) {
            cout << -1 << endl;
        } else {
            cout << k[0] << " " << k[1] << " " << k[2] << endl;
        }
    }
    return 0;
}

/*
3 5 7
0 1 2
*/
