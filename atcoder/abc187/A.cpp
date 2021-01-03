#include <iostream>
#include <string>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string a, b;
    cin >> a >> b;
    int ansA =0;
    for (char cha: a) {
        ansA += cha - '0';
    }
    int ansB = 0;
    for (char chb : b) {
        ansB += chb - '0';
    }
    cout << max(ansA, ansB) << endl;
    return 0;
}
