#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
LL a[MAX_N];
LL sum[MAX_N];
LL days[MAX_N];

void solve()
{
    LL n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = a[i] + sum[i - 1];
    }
    LL ans = 0;
    int m = n;
    for (int i = 1; i <= n; ++i) {
        if (sum[i] > x) {
            m = i;
            days[i] = 0;
            break;
        }
        LL day = (x - sum[i]) / i;
        while (day * i + sum[i] <= x) {
            ++day;
        }
        --day;
        days[i] = day + 1;
        ans += days[i];
    }
    /*
    */
    // dbg(m)
    // for (int i = 1; i <= m; ++i) {
    //     cout << i << " " << sum[i] << " " << days[i] << endl;
    // }
    // LL lstDay = 0;
    // for (int i = m; i >= 1; --i) {
    //     if (days[i] != lstDay) {
    //         ans += (days[i] - lstDay) * i;
    //         lstDay = days[i];
    //     }
    // }
    cout << ans << endl;
}

/*
sum[i] + day <= x

x - sum[i] >= day

2 + 3 * 1 <= x

2 + 3 * 5 <= x

1,2,2 -> 1,3,5
        day = 0

        sum[i] + day * i <= x
        day <= (x - sum[i]) / i

        x = 17
        sum[i] = 7

1 2 2 
2 3 3
3 4 4 -> 11
4 5
5 6
6
7
8
9
10
11

*/

/*

sum[i]

2 2
3 3
4 4
5 5 -> 2 * 4 + 1 * 5 = 5 + 8 = 13
6 6
7 7
8 8
9 9
10 10
*/

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