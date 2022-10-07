#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    vector<int> a;
    vector<int> b;
    a.push_back(c[0]);
    for (int i = 1; i < n; ++i) {
        if (c[i] > c[0]) {
            for (int j = i; j < n; ++j) {
                b.push_back(c[j]);
            }
            break;
        } else {
            a.push_back(c[i]);
        }
    }

    if (b.size() == 0) {
        cout << "-1" << endl;
    } else {
        cout << a.size() << endl;
        for (int x : a) {
            cout << x << " ";
        }
        cout << endl;

        cout << b.size() << endl;
        for (int x : b) {
            cout << x << " ";
        }
        cout << endl;
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
