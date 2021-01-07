#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        map<int, int> pos;
        int n = target.size();
        for (int i = 0; i < n; ++i) {
            pos[target[i]] = i;
        }
        int mx = 0;
        vector<int> seq;
        int sz = 0;
        for (int x : arr) {
            auto it = pos.find(x);
            if (it != pos.end()) {
                seq.push_back(it->second);
                mx = max(mx, it->second);
                ++sz;
            }
        }
        vector<int> dp(sz + 1, mx + 1);
        for (int x : seq) {
            dp[lower_bound(dp.begin(), dp.end(), x) - dp.begin()] = x;
        }
        int mxLenLIS = lower_bound(dp.begin(), dp.end(), mx + 1) - dp.begin();
        return target.size() - mxLenLIS;
    }
};