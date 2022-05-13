#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+100;
int a[MAX_N];
LL cnt[MAX_N];
int n;

int lowBit(int x)
{
    return x & (-x);
}

void add(int pos, int val)
{
    for (int i = pos; i <= n; i += lowBit(i)) {
        cnt[i] += val;
    }
}

LL gsum(int pos)
{
    // dbg(pos)
    LL ans = 0;
    for (int i = pos; i >= 1; i -= lowBit(i)) {
        ans += cnt[i];
    }
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[i] = 0;
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        // dbg(gsum(a[i]))
        ans += (i - 1 - gsum(a[i] - 1));
        add(a[i], 1);
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
