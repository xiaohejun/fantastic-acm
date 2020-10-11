#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    const int N = 75;
    LL f[N];
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < N; ++i) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
    while (n--) {
        int m;
        cin >> m;
        cout << f[m] << endl;
    }
    return 0;
}
