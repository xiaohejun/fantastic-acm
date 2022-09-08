#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX_N = 2e4 + 10;

vector<int> G[MAX_N];
int dfn[MAX_N];
int low[MAX_N]; // 不通过父亲节点能访问到的最小的时间戳
int fa[MAX_N];
int times;
int n, m;

void dfs(int u, vector<int> &ret)
{
    dfn[u] = low[u] = times++;
    int childNum = 0;
    bool isCutPoint = false;
    for (int v : G[u]) {
        if (dfn[v] == 0) { // v 没有被访问过
            childNum++;
            fa[v] = u;
            dfs(v, ret);
            low[u] = min(low[u], low[v]);
            if (fa[u] != -1 && low[v] >= dfn[u]) {
                isCutPoint = true;
            }
        } else if (fa[u] != v) { // v 被访问过，但是可能是u的父亲，是父亲不处理，只有祖先才能更新值
            /*
            如果这样写的话，就表示能走到的时间戳最小的节点，因为v节点
            可能之前被更新过，以下用例就找不到割点，预期割点是3
            6 7
            1 2
            2 3
            3 4
            4 1
            3 5
            5 6
            6 3
            */
            // low[u] = min(low[u], low[v]);

            // low[u] 不经过父亲节点能回到的时间戳最小的节点
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (fa[u] == -1 && childNum >= 2) {
        isCutPoint = true;
    }
    
    if (isCutPoint) {
        ret.push_back(u);
    }
}

void tarjan(vector<int> &ret)
{
    times = 1;
    memset(dfn, 0, sizeof(dfn));
    memset(fa, -1, sizeof(fa));

    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == 0) {
            dfs(i, ret);
        }
    }

    sort(ret.begin(), ret.end());
}

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> ret;
    tarjan(ret);

    cout << ret.size() << endl;
    for (int x : ret) {
        cout << x << " ";
    }

    return 0;
}
