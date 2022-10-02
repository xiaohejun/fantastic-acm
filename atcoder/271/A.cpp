#include <iostream>
using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;


int main(){
    // freopen("in.txt", "r", stdin);
    int x;
    while (~scanf("%d", &x)) {
        printf("%02X\n", x);
    }    
    return 0;
}
