#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int now = n;
        cout << "2" << endl;
        for (int i = n - 1; i >= 1; --i) {
            cout << i << " " << now << endl;
            now = (now + i + 1) / 2;
        }
    }
    return 0;
}

/*
1 2 -> 2
1 2 3 4 -> 3,4#4  2,4#3 
1 2 3 4 5 -> 4,5#5 3,5#4 2,4#3 1,3#2

1 2 3

1,2#2
*/
