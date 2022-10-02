#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n);

    for (int i = 0; i < n; ++i) cin >> d[i];

    vector<set<int>> a(n);
    a[0].insert(d[0]);

    for (int i = 1; i < n; ++i) {

        for (int ai_1 : a[i - 1]) {
            int ai = ai_1 + d[i];
            if (ai >= 0 && ai >= ai_1) {
                a[i].insert(ai);
            }

            ai = ai_1 - d[i];
            if (ai >= 0 && ai <= ai_1) {
                a[i].insert(ai);
            }
        }

    }

    if (a[n-1].size() != 1) {
        cout << "-1" << endl;
        return;
    }

    for (auto ait : a) {
        for (int x : ait) {
            cout << x << " ";
        }
    }

    cout << endl;
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
