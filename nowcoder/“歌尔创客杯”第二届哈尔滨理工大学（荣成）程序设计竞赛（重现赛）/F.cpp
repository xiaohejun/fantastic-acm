    #include <bits/stdc++.h>

    using namespace std;

    typedef long long LL;
    #define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
    const int MAX_N = 520;
    int n, m;
    vector<int> G[MAX_N];
    vector<int> ans;
    int in[MAX_N];

    int main(){
        //freopen("in.txt", "r", stdin);
        ios::sync_with_stdio(0); cin.tie(0);
        while (cin >> n >> m && n && m) {
            for (int i = 1; i <= n; ++i) G[i].clear();
            ans.clear();
            memset(in, 0, sizeof(in));
            int u, v;
            for (int i = 0; i < m; ++i) {
                cin >> u >> v;
                G[u].push_back(v);
                in[v]++;
            }
            priority_queue<int, vector<int>, greater<int>> que;
            for (int i = 1; i <= n; ++i) {
                if(!in[i]) {
                    que.push(i);
                }
            }
            while (!que.empty()) {
                u = que.top();
                que.pop();
                ans.push_back(u);
                for (int v : G[u]) {
                    in[v]--;
                    if (!in[v]) {
                        que.push(v);
                    }
                }
            }
            for (int x : ans) {
                cout << x << " ";
            }
            cout << endl;
        }
        return 0;
    }
