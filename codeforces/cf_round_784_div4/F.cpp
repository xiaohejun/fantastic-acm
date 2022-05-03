#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
int a[MAX_N];

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int l = -1;
        int r = n;
        LL lSum = 0;
        LL rSum = 0;
        int ans = 0;
        int curLen = 0;
        while (l < r) {
            if (lSum == rSum) {
                ans = max(ans, curLen);
                lSum += a[++l];
            } else if (lSum > rSum) {
                rSum += a[--r];
            } else {
                lSum += a[++l];
            }
            ++curLen;
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