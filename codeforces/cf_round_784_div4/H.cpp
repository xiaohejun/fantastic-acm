#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
unsigned int a[MAX_N];

#define IDX(a) (((a) - 'a'))

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n , k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        unsigned int ans = 0;
        for (int j = 30; j >= 0; --j) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (((a[i] >> j) & 1) == 0) {
                    ++cnt;
                }
            }
            if (k - cnt >= 0) {
                k -= cnt;
                ans |= (1LL << j);
            }
        }
        cout << ans << endl;
    }   
    return 0;
}
/*
len: 

n-2 --> 0

ans = n - len
*/