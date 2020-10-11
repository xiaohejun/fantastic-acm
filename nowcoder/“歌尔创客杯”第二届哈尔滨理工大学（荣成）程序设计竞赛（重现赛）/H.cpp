#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000+10;

//------------------------并查集的实现-----------
int par[MAX_N]; // 父亲
int rankk[MAX_N]; // 树的高度

void init(int n){ // 初始化n个元素
	for (int i = 0; i < n; ++i)
	{
		par[i] = i;
		rankk[i] = 0;
	}
}

// 查询树的根并且在查询的过程中把树简化
int findd(int x){
	return par[x] == x ? x : par[x]=findd(par[x]);
}

// 合并x和y所属的两个集合
void unite(int x, int y){
	x = findd(x); // 找到x所在集合的父亲
	y = findd(y); // 找到y所在集合的父亲
	if(x == y) return; // 在一个集合中
	if(rankk[x] < rankk[y]){ // x在的集合高度小
		par[x] = y; // 把x合并到集合y中
	} else {
		par[y] = x; // 把y合并到集合x中
		if(rankk[x] == rankk[y]) rankk[x]++; // 高度增加
	}
}

// 判断x和y是不是在一个集合中
bool same(int x, int y){
	return findd(x) == findd(y); // 判断他们的父亲是不是一个
}
//----------------------------------------------------

//----------------------------Kruskal算法----------------
const int MAX_E = 10000+10; // 最多的边数
const int MAX_V = 300+10; // 最多的结点数

struct edge // 边的信息
{
	int u,v,cost; // 点u到v这条边的权值是cost
};

bool comp(const edge &e1, const edge &e2){ // 比较用来排序
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int V,E; // 结点数,边数
bool used[MAX_V];

int kruskal(){ // kruskal算法
	memset(used, false, sizeof used);
	sort(es, es+E, comp); // 将边按权值来排序
	init(V); // 并查集的初始化
	int res = 0;
	for (int i = 0; i < E; ++i)
	{
		edge e = es[i];
		if(!same(e.u, e.v)){ // 不在一个集合,防止出现圈
			unite(e.u, e.v); // 加入到一个集合
			used[e.u] = used[e.v] = true;
            res = max(res, e.cost);
		}
	}
	return res;
}
//-----------------------------------------------------------
int main(){
	//freopen("in.txt", "r", stdin);
	while(cin >> V >> E) { // 输入结点数
	    for (int i = 0; i < E; ++i)
	    {
	    	int x,y,z;
	    	cin >> x >> y >> z;
	    	es[i].u = x; es[i].v = y; es[i].cost = z;
	    }
	    cout << V - 1 << " " << kruskal() << endl;
	}
	return 0;
}
