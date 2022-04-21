    #include <bits/stdc++.h>

    using namespace std;

    typedef long long LL;
    #define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

    int main(){
        // freopen("in.txt", "r", stdin);
        ios::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            if (n == 1 || m == 1) {
                if (max(n, m) > 2) {
                    cout << -1 << endl;
                    continue;
                }
            }
            int n1 = n - 1;
            int m1 = m - 1;
            int ans = max(n1, m1) * 2 - ((n1 & 1) != (m1 & 1));
            if (ans < 0) {
                ans = -1;
            }
            cout << ans << endl;
        }
        return 0;
    }

    /*
    max(n-1, m-1) * 2

    10 5
    9 4

    4 6
    3 5
    */