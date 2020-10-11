#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 2e5+100;
int a[MAX_N];
int n;

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        a[x] = i;
    }
    for(int i = 0; i < n; ++i){
        cin >> x;
        a[x] = ((i - a[x]) + n) % n;
    }
    sort(a+1, a+n+1);
    int ans = 0;
    for(int i = 1; i <= n;){
        int x = a[i];
        int cnt = 0;
        while(i <= n && a[i] == x){
            ++i;
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}

/*
0 ... n-1

1 2 3 4 5
2 3 4 5 1 2 3 4 5 1

5 4 3 2 1
1 2 3 4 5 1 2 3 4 5

1 3 2 4
4 2 3 1 4 2 3 1


1 2 3 4 5
2 3 4 5 1

1 2 3 4 5
5 1 2 3 4

*/