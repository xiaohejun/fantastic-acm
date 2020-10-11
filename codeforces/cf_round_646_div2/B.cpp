#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int ans;
string s;
int len;

void go(){
    for(int i = -1; i < len; ++i){
        int cnt = 0;
        int idx = 0;
        while(idx < len){
            if(idx <= i){
                if(s[idx++] != '1') ++cnt;
            } else {
                if(s[idx++] != '0') ++cnt;
            }
        }
        ans = min(ans, cnt);
    }          
}

int main(){
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        len = s.size();
        if(len <= 2){
            cout << 0 << endl;
        } else {
            ans = len;
            go();
            reverse(s.begin(), s.end());
            go();
            cout << ans << endl;
        }
    }
    return 0;
}

/*
010
101

O(n)

不能有 010

首先不想有010


对于一个1,想保留他的话，左边和右边都不能有0
1000000000
0000000001
0000000000
1111111111

*/