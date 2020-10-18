#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cout << (1 + n) * n / 2 - 1<< endl; 
    return 0;
}

/*
1 2 3 4 5 6
1 2
2 3
*/