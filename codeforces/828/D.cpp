#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

int getcnt(int x)
{
    int cnt = 0;
    while ((x % 2) == 0) {
        x = x / 2;
        ++cnt;
    }
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while ((x % 2) == 0) {
            x = x / 2;
            ++cnt;
        }
    }

    if (cnt >= n) {
        cout << 0 << endl;
        return;
    }

    /*
    1 2 4 8 16 32 
    */

    vector<int> v;
    int ans = 0;
    for (int i = n; i >= 2; --i) {
        int x = getcnt(i);
        if (x > 0) {
            v.push_back(x);
        }
    }

    sort(v.rbegin(), v.rend());

    for (int x : v) {
        cnt += x;
        ++ans;
        if (cnt >= n) {
            cout << ans << endl;
            return;
        }
    }
    cout << "-1" << endl;
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
