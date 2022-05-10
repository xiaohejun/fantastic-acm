#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 100+10;
int a[MAX_N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 0;
    bool same = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++cnt;
        } else if (i + 1 < n && a[i] == a[i + 1]) {
            same = true;
        }
    }
    if (cnt > 0) {
        cout << n - cnt << endl;
    } else {
        if (!same) {
            cout << n + 1 << endl;
        } else {
            cout << n << endl;
        }
    }
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
