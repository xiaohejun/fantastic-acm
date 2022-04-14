#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    // freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    int i = 0, j = 0;
    vector<int> c(m, 0);
    while (j < m) {
        if (i < n && j < m && a[i] < b[j]) {
            ++i;
        } else {
            c[j] = i;
            ++j;
        }
    }
    for (int x : c) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
