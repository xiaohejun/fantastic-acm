#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s) {
        if (c == '1') ++ans;
    }
    cout << ans << endl;
    return 0;
}
