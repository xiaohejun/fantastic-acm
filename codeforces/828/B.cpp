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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    LL sum = 0;
    LL oddNum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] & 1) {
            oddNum++;
        }
    }
    LL evenNum = n - oddNum;
    int t, x;
    LL sumE = 0;
    LL sumO = 1;
    vector<LL> qv[2];
    for (int i = 0; i < q; ++i) {
        cin >> t >> x;
        if (t == 0) {
            // 偶数加
            if ((sumE & 1) == 0) {
                sumE += x;
            }
            if ((sumO & 1) == 0) {
                sumO += x;
            }
        } else {
            // 奇数加
            if ((sumE & 1) == 1) {
                sumE += x;
            }
            if ((sumO & 1) == 1) {
                sumO += x;
            }
        }
        qv[0].push_back(sumE);
        qv[1].push_back(sumO - 1);
    }
    sumO--;
    for (int i = 0; i < q; ++i) {
        cout << sum + qv[0][i] * evenNum + qv[1][i] * oddNum << endl;
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
