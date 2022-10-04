#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

#define idx(ch) (ch - 'a')
#define toChar(i) ((char)(i + 'a'))

// set nxt[id] = j
bool setOK(int *nxt, int* has, int id, int nxtId)
{
    if (nxtId == id) {
        return false;
    }

    if (has[nxtId]) {
        return false;
    }

    bool isOk = true;
    nxt[id] = nxtId;
    has[nxtId] = 1;

    // 1，是否有人没有后继
    bool oneBad = false;
    for (int i = 0; i < 26; ++i) {
        if (nxt[i] == -1) {
            oneBad = true;
            break;
        }
    }

    if (oneBad) {
        // 是不是已经成圈了
        bool hasCir = false;
        for (int i = 0; i < 26 && !hasCir; ++i) {
            int has[26] = {0};
            int curI = i;
            has[curI] = 1;
            while (nxt[curI] != -1) {
                if (has[nxt[curI]]) {
                    hasCir = true;
                    break;
                }
                curI = nxt[curI];
                has[curI] = 1;
            }
        }
        if (hasCir) {
            isOk = false;
        }
    }

    if (!isOk) {
        nxt[id] = -1;
        has[nxtId] = 0;
    }
    return isOk;
}

void solve()
{
    int n;
    cin >> n;
    string t;
    cin >> t;
    string s(n, '#');
    int nxt[26] = {0};
    int has[26] = {0};
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; ++i) {
        int id = idx(t[i]);
        if (nxt[id] == -1) {
            for (int j = 0; j < 26; ++j) {
                if (setOK(nxt, has, id, j)) {
                    break;
                }
            }
        }
        s[i] = toChar(nxt[id]);
    }

    cout << s << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
