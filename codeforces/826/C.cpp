#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

bool ok(vector<int> &a, int s, int tarsum, int &mxL)
{
    int n = a.size() - 1;
    if (s > n) {
        return true;
    }

    dbg(tarsum)
    dbg(mxL)
    int curSum = 0;
    int curL = 0;
    for (int i = s; i <= n; ++i) {
        if (curSum < tarsum) {
            curSum += a[i];
            ++curL;
        } else if (curSum == tarsum) {
            mxL = max(mxL, curL);
            curSum = a[i];
            curL = 1;
            dbg(curSum)
        } else if (curSum > tarsum) {
            return false;
        }
    }

    dbg(curSum)
    if (curSum != tarsum) {
        return false;
    }
    mxL = max(mxL, curL);

    return true;
}

void solve()
{
    int n ;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int ans = n;
    int curSum = 0;
    for (int i = 1; i <= n; ++i) {
        curSum += a[i];
        int mxL = i;
        if (ok(a, i + 1, curSum, mxL)) {
            ans = min(ans, mxL);
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