class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int, int>> v;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            v.emplace_back(height[i], weight[i]);
        }
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        vector<int> a;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            a.push_back(v[i].second);
            mx = max(mx, v[i].second);
        }
        vector<int> dp(n, mx + 1);
        int ans = -1;
        for (int x : a) {
            int id = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
            dp[id] = x;
            ans = max(ans, id);
        }
        return ans + 1;
    }
};