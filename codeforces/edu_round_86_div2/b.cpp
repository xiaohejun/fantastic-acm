#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

void solve(){
    string t;
    cin >> t;
    int n = t.size();
    if(n == 1 || n == 2) cout << t << endl;
    else {
        // k=1
        bool ok = true;
        for(int i = 0; i < n && ok; ++i){
            ok &= (t[i] == t[0]);
        }
        if(ok){
            cout << t << endl;
            return;
        }
        // k=2
        string s = "";
        s += t[0];
        for(int i = 1; i < 2*n; ++i){
            s += ((s[i-1] - '0') ^ 1) + '0';
        }
        cout << s << endl;
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
t=111
|s| <= 2*|t|
t是s的子序列
s有最小的k
s[i] = s[i+k]
k=1
s[0] = s[1]
全部是s[0]

k = 2
s[0] = s[2]
s[1] = s[3]
110
1不行
2
k可以是2
xoxoxoxoxoxoxoxoxo
*/
