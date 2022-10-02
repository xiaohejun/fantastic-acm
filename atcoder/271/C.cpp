#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;


int main(){
    // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    set<int> a;
    int remNum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > n) {
            remNum++;
        } else {
            if (a.find(x) == a.end()) {
                a.insert(x);
            } else {
                remNum++;
            }
        }
    }

    if (a.size() == n) {
        cout << n << endl;
        return 0;
    }

    // 剩下的数字都小于n,数量<n
    vector<int> v;
    for (int x : a) {
        v.push_back(x);
    }

    // remNUm 重复的，>n的
    
    int num = v.size();
    int idx = 0;
    int ans = 0;
    while (true) {
        // get ans + 1
        int want = ans + 1;
        // dbg(want)
        if (idx < num && v[idx] == want) {
            ans++;
            ++idx;
            continue;
        }
        // 找不到
        if (remNum > 2) {
            remNum -= 2;
            ans++;
            continue;
        }

        // remNum < 2，0 or 1
        int has = num - idx;
        int need = 2 - remNum;
        if (has >= need) {
            remNum = 0;
            num -= need;
            ans++;
            continue;
        }

        // 啥方案都不行
        break;
    }

    cout << ans << endl;
    return 0;
}
