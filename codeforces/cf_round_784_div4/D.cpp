#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define ON

#ifdef ON
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x) ;
#endif

const int MAX_N = 1e5+10;
char a[MAX_N];
char b[MAX_N];

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> a;
        if (n == 1) {
            if (a[0] != 'W') {
                cout << "NO" << endl;
                continue;
            }
        }
        for (int i = 0; i < n; ++i) {
            b[i] = 'W';
        }
        bool ok = true;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == b[i]) {
                continue;
            }
            if (a[i] == 'W') {
                if (b[i] != 'W') {
                    ok = false;
                    dbg(ok)
                    break;
                }
            } else if (a[i] == 'R') {
                // BR
                if (i + 1 < n && b[i + 1] == 'B') {
                    b[i] = 'R';
                } else if (i - 1 >= 0) {
                    b[i - 1] = 'B';
                    b[i] = 'R';
                } else {
                    dbg(i)
                    ok = false;
                }
            } else if (a[i] == 'B') {
                // RB
                dbg(a)
                dbg(b)
                if (i + 1 < n && b[i + 1] == 'R') {
                    b[i] = 'B';
                } else if (i - 1 >= 0) {
                    b[i - 1] = 'R';
                    b[i] = 'B';
                } else {
                    dbg(i)
                    ok = false;
                }
            }
            if (a[i] != b[i]) {
                ok = false;
                dbg(i)
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }   
    return 0;
}

/*
BR
RB

BR
RB
BRB
RBR
RRB
BBR
BRRB
RBBR


RB
 RB
*/