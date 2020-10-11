#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << endl;
#define x first
#define y second
typedef long long LL;
typedef pair<LL, LL> PII;
const int MAX_N = 1e3+100;
const int MOD[2] = {(int)1e9+7, (int)1e9+9};
const int P = 1e7+17;
LL powN[2][MAX_N];
vector<LL> hashValue[2][2];
char s[2][MAX_N];
int ans;
int len1, len2;

void init_pow(){
    for(int i = 0; i < 2; ++i){
        powN[i][0] = 1LL;
        for(int j = 1; j < MAX_N; ++j){
            powN[i][j] = powN[i][j-1] * P % MOD[i];
        }
    }}

void init(int idx){
    int len = strlen(s[idx]);
    for(int i = 0; i < 2; ++i){
        hashValue[i][idx].push_back(0);
        for(int j = 1; j <= len; ++j){
            hashValue[i][idx].push_back((hashValue[i][idx][j-1] * P + s[idx][j-1]) % MOD[i]);
        }
    }
}

PII getHash(int idx, int l, int r){
    vector<int> ans;
    for(int i = 0; i < 2; ++i){
        ans.push_back(((hashValue[i][idx][r] - hashValue[i][idx][l-1] * powN[i][r-l+1]) % MOD[i] + MOD[i]) % MOD[i]);
    }
    return make_pair(ans[0], ans[1]);
}

bool equ(PII a, PII b){
    return (a.x == b.x) && (a.y == b.y);
}

void solve() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            hashValue[i][j].clear();
        }
    }
    len1 = strlen(s[0]);
    len2 = strlen(s[1]);
    init(0);
    init(1);
    int ans = 0;
    PII b = getHash(1, 1, len2);
    for (int i = 0; i + len2 - 1 < len1;) {
        int l = i;
        int r = i + len2 - 1;
        PII a = getHash(0, l+1, r+1);
        if (equ(a, b)) {
            i += len2;
            ++ans;
        } else {
            ++i;
        }
    }
    cout << ans << endl;
}

int main(){
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    init_pow();
    while (cin >> s[0] >> s[1] && s[0][0] != '#') {
        solve();
    }
    return 0;
}
