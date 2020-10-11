#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
int n;

struct P{
    int p, t;
};

int main(){
    //freopen("in.txt", "r", stdin);
    cin >> n;
    int c, t, p;
    LL ans = 0;
    vector<P> que;
    for (int i = 0; i < n; ++i) {
        cin >> c >> p >> t;
        if (c == 0) {
            que.push_back((P){p, t});
            ans += p;
        } else {
            bool ok = false;
            for (vector<P>::iterator it = que.begin(); it != que.end(); ) {
                if (t - it->t > 45) {
                    que.erase(it);
                    continue;
                }
                if (t - it->t <= 45 && p <= it->p) {
                    ok = true;
                    que.erase(it);
                    break;
                }
                ++it;
            }
            if (!ok) {
                ans += p;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
