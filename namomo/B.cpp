#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    string a = "a";

    return 0;
}


/*
辅元

xyijij

x i 辅
y j 元

x 可以等于i
y 可以等于j

找ij这样的字符串
ij的个数cnt
cnt >= 3
ans += C(cnt, 3)
cnt >= 2
如果前面有xy
ans += cnt - 2 + 1  -> ans += cnt - 1
*/