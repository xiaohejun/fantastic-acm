#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

int get(const string &s)
{
    int val = 0;
    int n = s.size();
    char c = s[n - 1];
    int x = 0;
    if (c == 'S') {
        x = -1;
        val = -1;
    } if (c == 'L') {
        x = 1;
        val = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        val += x;
    }
    return val;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    /*
    The T-shirt size is either a string M 
    or a string consisting of several (possibly zero) characters X and one of the characters S or L.
    */
    // xxxs M xxxxL
    int aval = get(a);
    int bval = get(b);
    if (aval < bval) {
        cout << "<" << endl;
    } else if (aval == bval) {
        cout << "=" << endl;
    } else {
        cout << ">" << endl;
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
