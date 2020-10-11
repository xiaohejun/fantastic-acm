#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

bool kmp(string W, string T){
    int n, m;
    m = W.size();
    int i,j;
    int nxt[m+1];
    j = nxt[0] = -1;
    i = 0;
    while(i < m){
        while(j != -1 && W[i] != W[j]) j = nxt[j];
        nxt[++i] = ++j;
    }
    n = T.size();
    for(i = 0, j = 0; i < n; ++i){
        if(j < m && W[j] == T[i]){
            ++j;
        } else {
            while(j > 0){
                j = nxt[j];
                if(W[j] == T[i]){
                    ++j;
                    break;
                }
            }
        }
        if(j == m) return true;
    }
    return false;
}

int main(){
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    if (n > m) {
        cout << 0 << endl;
        return 0;
    }
    // n <= m
    set<string> st;
    for (int i = 0; i + n - 1 < m; ++i) {
        st.insert(t.substr(i, n));
    }
    int cnt[26] = {0};
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
    }
    int tmp[26] = {0};
    int ans = 0;
    for (set<string>::iterator it = st.begin(); it != st.end(); ++it) {
        memset(tmp, 0, sizeof(tmp));
        int p = it->size();
        for (int i = 0; i < p; ++i) {
            tmp[(*it)[i]-'a']++;
        }
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (tmp[i] != cnt[i]) {
                ok = false;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}
