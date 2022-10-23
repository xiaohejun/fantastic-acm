#include <bits/stdc++.h>
using namespace std;

// 类型定义
typedef long long LL;

#ifndef ONLINE_JUDGE
    #include "../../algo/debug.h"
#else
    #define dbg(x...)
#endif
#define fastio ios::sync_with_stdio(0); cin.tie(0);


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> color(n + 1, -1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2 != 0) {
        cout << "-1" << endl;
        return;
    }

    int needNum = sum / 2;
    int target = 1;
    if (needNum < 0) {
        needNum = -needNum;
        target = -1;
    }

    int colorV = 0;
    dbg(target)
    dbg(needNum)
    for (int i = 2; i <= n && needNum > 0; ++i) {
        if (a[i] == target && color[i - 1] == -1) {
            --needNum;
            color[i - 1] = colorV;
            color[i] = colorV;
            ++colorV;
        }
    }

    dbg(needNum)
    if (needNum > 0) {
        cout << "-1" << endl;
        return;
    }

    dbg(color)
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n;) {
        int cur = color[i];
        int curI = i;
        int curJ = i;
        while (i <= n && color[i] == cur) {
            curJ = i;
            ++i;
        }
        ans.push_back(make_pair(curI, curJ));
    }

    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    fastio;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
