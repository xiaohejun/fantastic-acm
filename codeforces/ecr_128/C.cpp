#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e5+10;
char s[MAX_N];
int cnt1L[MAX_N];
int cnt1R[MAX_N];


/*
cost 一开始 = 当前有多少0

cost = max(cnt0, del1Cnt)

记录每个0的左边有多少个1
右边有多少个1

011011 0220 110

100 1001001001
    ｜      

1
init cost = max(cnt0 = 8, del1Cnt = 0) = 8
*/

void solve()
{
    cin >> s;
    int n = strlen(s);
    int cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++cnt0;
        }
    }
    int cost = min(cnt0, n - cnt0);
    
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        cnt1L[i] = cnt1;
        if (s[i] == '1') {
            ++cnt1;
        }
    }
    cnt1 = 0;
    for (int i = n - 1; i >= 0; --i) {
        cnt1R[i] = cnt1;
        if (s[i] == '1') {
            ++cnt1;
        }
    }

    for (int l = 0; l < n; ++l) {
        int curL = l;
        int curR = n - 1;
        while (curL <= curR) {
            int mid = (curL + curR) / 2;
            if (cnt1L[l] + cnt1R[mid] > Cnt0(curL, mid)) {
                
            }
        }
        if (s[l] == '1') {
            ++cnt1;
        }
    }

    cout << cost << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
cnt1

cnt0

(i, j)

*/