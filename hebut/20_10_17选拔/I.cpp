#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;


struct edge {
	int to,cost; 
	edge(int t, int c):to(t),cost(c){}
};

typedef pair<int, int> P; 

const int MAX_V = 510;
const int INF = 1 << 30; // 权值最大值
vector<edge> G[MAX_V];
int d[MAX_V]; 
int M, N;


void dijkstra(int s){
    fill(d, d + N + 1, INF);
	priority_queue<P, vector<P>, greater<P> > que;
	d[s] = 0;
	que.push(P(0,s)); 
	while(!que.empty()){
        P p = que.top(); que.pop(); 
        int v = p.second;
        if(d[v] < p.first) continue; 
        for(int i = 0; i < (int)G[v].size(); i++){ 
            edge e = G[v][i]; 
            if(d[e.to] > d[v] + e.cost){ 
                d[e.to] = d[v] + e.cost; 
                que.push(P(d[e.to], e.to));
            }
        }
	}
}

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    string str;
    getline(cin, str);
    while (getline(cin, str)) {
        istringstream is(str);
        int x;
        vector<int> v;
        while (is >> x) {
            v.push_back(x);
        }
        int sz = v.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                G[v[i]].push_back(edge(v[j], 1));
            }
        }
    }
    dijkstra(1);
    if (d[N] == INF) {
        cout << "NO" << endl;
    } else {
        cout << d[N] - 1<< endl;
    }
    return 0;
}

/*
M N
3 7
*/