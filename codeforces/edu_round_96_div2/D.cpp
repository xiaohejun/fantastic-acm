#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < n;) {
            char c = s[i];
            int cnt = 0;
            while (i < n && s[i] == c) {
                ++i;
                ++cnt;
            }
            v.push_back(cnt);
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                que.push(i);
            }
        }
        int sz = v.size();
        int del = 0;
        int now = 0;
        int ans = 0;
        for (int i = 0; i < sz; ++i) {
            while (!que.empty() && que.front() <= i) {
                que.pop();
            }
            if (v[i] > 1) {

            } else {

            }
            ++ans;
            now += v[i];
        }
    }
    return 0;
}