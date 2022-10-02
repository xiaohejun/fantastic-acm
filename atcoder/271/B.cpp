#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;


int main(){
    // freopen("in.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < q; ++i) {
        int s, t;
        cin >> s >> t;
        cout << v[s - 1][t - 1] << endl;
    }
    return 0;
}
