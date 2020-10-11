#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

struct P{
    int m, c;
};

struct segtree {
    int size;
    vector<P> tree;
 
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(2 * size); 
    }

    void f(P &c, P a, P b) {
        if (a.m == b.m) {
            c.m = a.m;
            c.c = a.c + b.c;
        } else if (a.m < b.m) {
            c = a;
        } else {
            c = b;
        }
    }

    void build(vector<int> &a, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tree[idx].m = a[lx];
                tree[idx].c = 1;
            }
            return;
        }
        int m = (lx + rx) >> 1;
        build(a, 2 * idx + 1, lx, m);
        build(a, 2 * idx + 2, m, rx);
        f(tree[idx], tree[2 * idx + 1], tree[2 * idx + 2]);
    }
 
    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }
 
    void set(int i, int v, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx].m = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m) {
            set(i, v, 2 * idx + 1, lx, m);
        } else {
            set(i, v, 2 * idx + 2, m, rx);
        }
        f(tree[idx], tree[2 * idx + 1], tree[2 * idx + 2]);
    }
 
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
 
    P calc(int l, int r, int idx, int lx, int rx) {
        if (r <= lx || l >= rx) return (P){INT_MAX, 1};
        if (l <= lx && rx <= r) return tree[idx];
        int m = (lx + rx) >> 1;
        P a1 = calc(l, r, 2 * idx + 1, lx, m);
        P a2 = calc(l, r, 2 * idx + 2, m, rx);
        P c;
        f(c, a1, a2);
        return c;
    }
 
    P calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
 
};
 
int main(){
    //freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    segtree st;
    st.init(n);
    st.build(a);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            P ans = st.calc(l, r);
            cout << ans.m << " " << ans.c << endl;
        }
    }
    return 0;
}
