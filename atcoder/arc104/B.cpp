#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int Idx(char c)
{
    string s = "ATCG";
    for (int i = 0; i < (int)s.length(); ++i) {
        if (c == s[i]) {
            return i;
        }
    }
    return -1;
}

bool Check(int l, int r, vector<vector<int>> &sum)
{  
    vector<int> tmp(4);
    for (int i = 0; i < 4; ++i) {
        tmp[i] = sum[i][r] - sum[i][l - 1];
    }
    for (int i = 0; i < 4; i += 2) {
        if (tmp[i] != tmp[i + 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> sum(4, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        int id = Idx(s[i]);
        for (int j = 0; j < 4; ++j) {
            sum[j][i + 1] = sum[j][i];
        }
        sum[id][i + 1]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (Check(i, j, sum)) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
