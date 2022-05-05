#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
int a[MAX_N];
int n;

void solve()
{
   cin >> n;
   for (int i = 0; i < n; ++i) {
       cin >> a[i];
   }
   if (a[n - 1] - a[0] - n + 1 <= 2) {
       cout << "YES" << endl;
   } else {
       cout << "NO" << endl;
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

/*
最终
a[n - 1] - a[0] + 1 <= n + 2

*/