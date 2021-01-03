#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    set<string> st1, st2;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[0] == '!') {
            s = s.substr(1, s.size() - 1);
            if (st1.find(s) != st1.end()) {
                cout << s << endl;
                return 0;
            }
            st2.insert(s);
        } else {
            if (st2.find(s) != st2.end()) {
                cout << s << endl;
                return 0;
            }
            st1.insert(s);
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}
