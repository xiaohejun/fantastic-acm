#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    int sx, sy;
    cin >> n >> m;
    cin >> sx >> sy;
    cout << sx << " " << sy << endl;
    int x = sx, y = sy;
    while (y <= m) {
        y++;
        if (y <= m) {
            cout << x << " " << y << endl;
        }
    }
    y = sy;
    while (y >= 1) {
        y--;
        if (y >= 1) {
            cout << x << " " << y << endl;
        }
    }
    int dir[4][2] = {{-1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int k = 0;
    while (1) {
        while (1) {
            
        }
    }
    return 0;
}
