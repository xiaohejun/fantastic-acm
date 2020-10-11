#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b;
    cin >> a >> b;
    int x = (a + b) / 2;
    int y = a - x;
    cout << x << " " << y << endl;
    return 0;
}
