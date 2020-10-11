#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

const int MAX = 55;

int main(){
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    int n, m;
    cin >> t;
    while(t--){
        int x;
        int r[MAX] = {0}, c[MAX] = {0};
        cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin >> x;
                if(x){
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        int a = 0;
        for(int i = 1; i <= n; ++i){
            if(r[i] == 0) ++a;
        }
        int b = 0;
        for(int i = 1; i <= m; ++i){
            if(c[i] == 0) ++b;
        }
        puts(min(a, b) & 1 ? "Ashish" : "Vivek");
    }
    return 0;
}

/*
被伤害的行和列
剩下的行和列
有些点可以同时搞行和列
单搞行
单搞列

搞完的赢


*/