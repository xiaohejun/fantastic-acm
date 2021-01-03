#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i  = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }    
    LL sum = 0;
    vector<LL> c;
    for (int i = 0; i < n; ++i) {
        c.push_back(2 * a[i] + b[i]);
        sum -= a[i];
    }
    sort(c.rbegin(), c.rend());
    for (int i = 0; i < n; ++i) {
        sum += c[i];
        if (sum > 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}