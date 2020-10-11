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
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < n;) {
            char c = s[i];
            int cnt = 0;
            while (i < n && s[i] == c) {
                ++i;
                ++cnt;
            }
            v.push_back(cnt);
        }
        int sz = v.size();
        int idx = 0;
        int ans = 0;
        while (idx < sz) {
            if (v[idx] == 1) {
                // nxt
                if (idx + 1 < sz) {
                    if (v[idx + 1] == 1) {
                        ++ans;
                        idx += 2;
                    } else {
                        v[idx + 1]--;
                        ++ans;
                        ++idx;
                    }
                } else {
                    ++ans;
                    ++idx;
                }
            } else {
                ++ans;
                ++idx;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
7
6
111010
1
0
1
1
2
11
6
101010
7
0101111
3
011
*/
