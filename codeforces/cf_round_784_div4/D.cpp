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
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> a;
        bool ok = true;
        int rCnt = 0;
        int bCnt = 0;
        for (int i = 0; i <= n && ok; ++i) {
            char c = 'W';
            if (i < n) {
                c = a[i];
            }
            if (c == 'W') {
                if (rCnt + bCnt == 1 ||
                    (rCnt == 0 && bCnt > 0) ||
                    (bCnt == 0 && rCnt > 0)) {
                    ok = false;
                }
                rCnt = 0;
                bCnt = 0;
            } else {
                if (c == 'R') {
                    ++rCnt;
                } else {
                    ++bCnt;
                }
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