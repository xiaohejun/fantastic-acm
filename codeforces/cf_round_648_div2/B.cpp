#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int lst = -1, now;
        bool ok = true;
        for(int i = 0; i < n; i++){
            cin >> now;
            ok &= (now >= lst);
            lst = now;
        }   
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> now;
            cnt += now;
        }
        ok = ok || (0 < cnt && cnt < n);
        puts(ok ? "Yes" : "No");
    }
    return 0;
}
