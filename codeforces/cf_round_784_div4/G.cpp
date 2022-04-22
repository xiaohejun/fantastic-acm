#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 55;
const int MAX_M = 55;
char s[MAX_N][MAX_M];

#define IDX(a) (((a) - 'a'))

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '*') {
                    // move down
                    int nxti = i + 1;
                    while (nxti < n) {
                        char c = s[nxti][j];
                        if (c == 'o' || c == '*') {
                            break;
                        } else {
                            ++nxti;
                        }
                    }
                    if (nxti - 1 != i) {
                        s[nxti - 1][j] = '*';
                        s[i][j] = '.';
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << s[i] << endl;
        }
    }   
    return 0;
}
/*
len: 

n-2 --> 0

ans = n - len
*/