#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    int r = n - 1;
    bool isP = true;
    while (l <= r) {
        if (s[l] != s[r]) {
            isP = false;
            break;
        }
        ++l;
        --r;
    }
    if (!isP) {
        cout << n << endl;
    } else {
        bool isSame = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[0]) {
                isSame = false;
                break;
            }
        }
        cout << (isSame ? 0 : n - 1) << endl;
    }
    return 0;
}
/*
abcba

*/