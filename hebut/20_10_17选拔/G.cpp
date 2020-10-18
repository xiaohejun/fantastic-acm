#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MOD = 1e9+7;
const int MAX_N = 1e6+10;
bool is[MAX_N];

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> p;
    memset(is, true, sizeof(is));
    for (int i = 2; i <= n; i++) {
        if (is[i]) {
            p.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                is[j] = false;
            }
        }
    }
    LL ans = 1;
    for (int x : p) {
        int sum = 0;
        int tmp = n;
        while (tmp) {
            sum += tmp / x;
            tmp /= x;
        }
        ans = (2LL * sum + 1LL) % MOD * ans % MOD;
    }
    cout << ans << endl;
    return 0;
}

/*
x + y  1
x*y    fac(n)

x*y = (x + y)*fac(n)

???正
x = fac(n) + a
y = fac(n) + b
n = fac(n)
(n + a) * (n + b)
n ^ 2 + (a + b)n + ab = n(2n + a + b) = 2n^2 + (a + b)n
n^2 = ab

2 * 2 = 4
a b
1 4 -> 3 6
2 2 -> 4 4
4 1 -> 6 3

*/