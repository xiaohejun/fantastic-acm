#include<iostream> 
#include<string>   
using namespace std;   

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int mx[10] = {0};
    for (int i = 9; i >= 1; --i) {
        LL mod = 0;
        for (int j = 1; j <= n; ++j) {
            mod = (mod * 10 % m + i) % m;
            if (mod == 0) {
                mx[i] = j;
            }
        }
    }

    int mxj = 0;
    for (int i = 1; i <= 9; ++i) {
        mxj = max(mxj, mx[i]);
    }

    bool find = false;
    for (int i = 9; i >= 1 && !find && mxj != 0; --i) {
        if (mx[i] == mxj) {
            find = true;
            for (int j = 0; j < mxj; ++j) {
                cout << i;
            }
            cout << endl;
        }
    }
    
    if (!find) {
        cout << "-1" << endl;
    }

    return 0;
}