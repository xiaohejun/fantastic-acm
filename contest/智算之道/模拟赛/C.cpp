#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 1e4+100;
int T, N;
LL M;
LL f[MAX_N];
LL p[110][110];

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T >> N >> M;
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> p[i][j];
        }
    }
    for (int i = 1; i < T; ++i) {
        memset(f, 0, sizeof(f));
        for (int j = 0; j < N; ++j) {
            LL w = p[i][j] - p[i - 1][j];
            if (w > 0) {
                for (int k = p[i - 1][j]; k <= M; ++k) {
                    f[k] = max(f[k], f[k - p[i - 1][j]] + w);
                }
            }
        }
        M += f[M];
    }
    cout << M << endl;
    return 0;
}
