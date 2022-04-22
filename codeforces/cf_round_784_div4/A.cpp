#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int ra;
        cin >> ra;
        if (ra >= 1900) {
            cout << "Division 1" << endl;
        } else if (ra >= 1600) {
            cout << "Division 2" << endl;
        } else if (ra >= 1400) {
            cout << "Division 3" << endl;
        } else {
            cout << "Division 4" << endl;
        }
    }
    return 0;
}
