#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a = 0;
        int tmp;
        for(int i = 0; i < n; ++i){
            cin >> tmp;
            a += (tmp & 1);
        }
        int b = n - a;
        bool flag = false;
        if(a != 0){ // 肯定得有奇
            // 单出一个奇
            --x;
            --a;
            // 现在需要补x个数字，x个数字和是偶
            // 2个奇可以凑偶，1个偶凑偶
            if(b >= x){
                flag = true;
            } else { // b < x
                x -= b; // 先拿偶数顶
                if(x&1){ // x是奇数
                    if(b){ // 有偶数,少拿一个
                        ++x;
                        flag = x / 2 <= a / 2;
                    } else { // 没有偶数。直接gg
                        
                    }
                } else { // x是偶数
                    flag = x / 2 <= a / 2;
                }
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}

/*
x是奇数
奇+偶

x是偶数


n a b x
1 1 0 1
1 0 1 1
2 1 1 1

2 2 2 3 3
0 0 0 1 1
两个。必须成对

x
() 偶 偶


_k * 2 + _b == x
_k  (0...k)
_b  (0...b)

x-_b 必须是偶
*/
