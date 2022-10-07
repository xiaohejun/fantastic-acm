#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_K = 1e9+10;

void calcDmin(const string &s, vector<int> &d, char c)
{
    int n = s.size();
    vector<int> tmp(n, MAX_K);
    for (int i = 0; i < n; ++i) {
        if (s[i] != c) {
            tmp[i] = 0;
        } else if (i != 0) {
            tmp[i] = tmp[i - 1] + 1;
        }
        d[i] = min(d[i], tmp[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != c) {
            tmp[i] = 0;
        } else if (i != n - 1) {
            tmp[i] = tmp[i + 1] + 1;
        }
        d[i] = min(d[i], tmp[i]);
    }

    // dbg(c)
    // for (int i = 0; i < n; ++i) {
    //     dbg(d[i])
    // }
    // dbg("----")
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> d1(n, MAX_K);
    vector<int> d0(n, MAX_K);

    calcDmin(s, d1, '1');
    calcDmin(s, d0, '0');

    string t(n, '#');
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (d1[i] == MAX_K) {
                t[i] = '0';
            } else {
                if (k <= d1[i]) {
                    t[i] = '0';
                } else {
                    if ((k - d1[i]) & 1) {
                        t[i] = '1';
                    } else {
                        t[i] = '0';
                    }
                }
            }
        } else {
            if (d0[i] == MAX_K) {
                t[i] = '0';
            } else {
                if (k < d0[i]) {
                    t[i] = '0';
                } else {
                    if ((k - (d0[i] - 1)) & 1) {
                        t[i] = '1';
                    } else {
                        t[i] = '0';
                    }
                }
            }
        }
    }

    cout << t << endl;
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
