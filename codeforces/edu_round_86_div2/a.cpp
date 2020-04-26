#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        LL x, y, a, b;
        cin >> x >> y >> a >> b;
        LL mn = min(x, y);
        LL mx = max(x, y);
        cout << min(mn * b + (mx - mn) * a, (x + y) *a) << endl;
    }
    return 0;
}

/*
a dollars: 其中一个减或者加1
b dollars: 两个同时减或者加1
x y
mn = min(x, y)
1: 同时 mn * b
   分别 
*/