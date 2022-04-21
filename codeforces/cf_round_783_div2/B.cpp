#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 1e5+10;
int a[MAX_N];

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n >= m) {
            cout << "NO" << endl;
            continue;
        }
        sort(a, a + n);
        bool ok = true;
        for (int i = n - 1; i >= 0; --i) {
            --m;
            if (m < 0) {
                ok = false;
                break;
            }
            m -= a[i];
            if (m < 0) {
                ok = false;
                break;
            }
        }
        if (ok) { // m >= 0
            if (m + a[0] < a[n - 1]) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}

/*


- - - -
|   |

3 8
1 2 1

1_ 1 _2 4 _2 7 _4

4 12
1 2 1 3
no

排序，
大的先安排



*/