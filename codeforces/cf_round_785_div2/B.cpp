#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

/*
有一个子串
有字母出现次数>=2
有字母出现次数0
双指针，保持出现次数>=2
*/
bool isNotOk(string &s, char c, int *oriCnt)
{
    int cnt[26] = {0};
    int l = 0;
    int r = 0;
    int n = s.size();
    int nxtI = n;
    for (int i = 0; i < n; i++) {
        if (s[i] != c) {
            continue;
        }
        memset(cnt, 0, sizeof(cnt));
        cnt[s[i] - 'a']++;
        nxtI = i + 1;
        for (; nxtI < n; ++nxtI) {
            cnt[s[nxtI] - 'a']++;
            if (s[nxtI] == c) {
                break;
            }
        }
        if (nxtI >= n) {
            break;
        }
        i = nxtI - 1;
        for (int j = 0; j < 26; ++j) {
            if ((cnt[j] > 0) != (oriCnt[j] > 0)) {
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt[26] = {0};
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (isNotOk(s, c, cnt)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
