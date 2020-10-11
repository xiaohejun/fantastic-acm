#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 1e5+100;
bool is[MAX_N];
int n, m;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    memset(is, true, sizeof(is));
    cin >> n >> m;
    while (m--) {
        int x;
        cin >> x;
        for (int i = x; i <= n; i += x) {
            is[i] = false;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += is[i];
    }
    cout << ans << endl;
    return 0;
}
