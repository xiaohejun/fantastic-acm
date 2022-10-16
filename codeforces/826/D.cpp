#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

int merge(vector<int> &a, int l, int m, int r)
{
    int ret = 0;
    if (a[l] > a[m + 1]) {
        ret = 1;
        for (int i = l, j = m + 1; i <= m; ++i, ++j) {
            swap(a[i], a[j]);
        }
    }
    return ret;
}

int mergesort(vector<int> &a, int l, int r)
{
    if (l == r) {
        return 0;
    }
    int m = (l + r) >> 1;
    int ans = 0;
    ans += mergesort(a, l, m);
    ans += mergesort(a, m + 1, r);
    ans += merge(a, l, m, r);

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    dbg(n)
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "0" << endl;
        return;
    }
    dbg("--")
    for (int i = 0; i < n; i += 2) {
        if (abs(a[i] - a[i + 1]) > 1) {
            cout << "-1" << endl;
            return;
        }
    }
    int ans = mergesort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (a[i] != (i + 1)) {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
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


/*


 
7 8 4 3 1 2 6 5

*/