#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
int a[MAX_N];
bool can[MAX_N];

void solve()
{
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i) {
       cin >> a[i];
       can[i] = true;
   }
   bool ok = true;
   for (int i = 1; i < n; ++i) {
        int det = a[i] - a[i - 1] - 1;
        // dbg(i)
        // dbg(det)
        // dbg(a[i])
        // dbg(a[i - 1])
        // dbg(i)
        // dbg(det)
        // for (int j = 0; j < n; ++j) {
        //     cout << a[j] << " ";
        // }
        // cout << endl;
        // for (int j = 0; j < n; ++j) {
        //     cout << can[j] << " ";
        // }
        // cout << endl;
        if (det == 0) {
        } else if (det == 1) {
            // i - 1 move + 1 ? i move - 1
            if (can[i - 1]) {
                a[i - 1]++;
            } else if (can[i]) {
                a[i]--;
            } else {
                ok = false;
                break;
            }
        } else if (det == 2 && can[i] && can[i - 1]) {
            a[i]--;
            a[i - 1]++;
        } else {
            ok = false;
            break;
        }
        can[i] = false;
        can[i - 1] = false;
   }
   cout << (ok ? "YES" : "NO") << endl;
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
