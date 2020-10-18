#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    LL x, y;
    cin >> x >> y;
    LL a = (x + y) / 2;
    LL b = a - y;
    cout << a << " " << b << endl;
    return 0;
}

/*
a + b = x
a - b = y
*/