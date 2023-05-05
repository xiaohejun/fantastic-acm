#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = i - a[i] + 1;
    }

    LL cnt = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        j = max(i, j);
        while (j < n && a[j] <= i) {
            ++j;
        }
        cnt += (j - i);
    }

    cout << cnt << endl;
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