#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define on

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

const int MAX_N = 35;
int a[MAX_N];

int fa[26];

void init()
{
    for (int i = 0; i < 26; ++i) {
        fa[i] = i;
    }
}

int find(int u)
{
    return fa[u] = (fa[u] == u ? u : find(fa[u]));
}

void unionI(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u < v) {
        fa[v] = u;
    } else {
        fa[u] = v;
    }
}

bool same(int u, int v)
{
    return find(u) == find(v);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    init();
    for (int i = 0; i < n && k >= 0; ++i) {
        char c = s[i];
        char toC = '#';
        int step = c - 'a';
        if (step <= k) {
            toC = 'a';
        } else {
            toC = (char)(c - k);
            step = c - toC;
        }
        if (!same(c - 'a', toC - 'a')) {
            for (char cur = toC; cur <= c; ++cur) {
                if (!same(toC - 'a', cur - 'a')) {
                    unionI(toC - 'a', cur - 'a');
                    --k;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        cout << (char)(find(c - 'a') + 'a');
    }
    cout << endl;
}

/*
x -> y


所有<=x的都能变成y，除了'z' -> 'a'
a b c d e f g h i j k l m n o p q r s t u v w x y z
*/

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
/*
4 5
fgde

f->e
e->d
d->c
c->b
b->a

a b c d e f g
*/
