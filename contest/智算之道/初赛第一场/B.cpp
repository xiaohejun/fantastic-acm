#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int chk(string s) {
    int n = s.size();
    int ans = 1e9;
    for (int i = 0; i < (1 << n); ++i) {
        string t = s;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j)&1) {
                ++cnt;
                for (int k = 0; k <= j; ++k) {
                    t[k] = ((t[k] - '0') ^ 1) + '0';
                }
            }
        }
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (t[j] != '0') {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = min(ans, cnt);
        }
    }
    return ans;
}

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    char c = '#';
    int ans = 0;
    for (int i = 0; i < n;) {
        c = s[i];
        while (i < n && s[i] == c) ++i;
        ++ans;
    }
    if (c == '0') {
        --ans;
    }
    cout << ans << endl;
    return 0;
}

/*
0的地方偶数次
1的地方奇数次
f[i] 表示把i之前全部变成0需要的最少操作次数
if (a[i] == 1) {
    f[i] 
} else {
    f[i] = f[i - 1];
}
*/