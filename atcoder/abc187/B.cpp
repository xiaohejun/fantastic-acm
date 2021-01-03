#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

bool InRange(pair<int, int> p, pair<int, int> q)
{
    int x = q.first - p.first;
    int y = q.second - p.second;
    double ret = (double)y / (double)x;
    return -1 <= ret && ret <= 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0;i < n; ++i) {
        cin >> v[i].first >> v[i].second; 
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto pi = v[i];
        for (int j = i + 1; j < n; ++j) {
            auto pj = v[j];
            if (InRange(pi, pj)) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
