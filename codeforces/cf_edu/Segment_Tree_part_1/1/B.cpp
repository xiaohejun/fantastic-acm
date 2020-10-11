#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
 
struct segtree {
    int size;
    vector<int> tree;
 
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0); 
    }
 
    void build(vector<int> &a, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tree[idx] = a[lx];
            }
            return;
        }
        int m = (lx + rx) >> 1;
        build(a, 2 * idx + 1, lx, m);
        build(a, 2 * idx + 2, m, rx);
        tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
 
    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }
 
    void set(int i, int v, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m) {
            set(i, v, 2 * idx + 1, lx, m);
        } else {
            set(i, v, 2 * idx + 2, m, rx);
        }
        tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
 
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
 
    int calc(int l, int r, int idx, int lx, int rx) {
        if (r <= lx || l >= rx) return INT_MAX;
        if (l <= lx && rx <= r) return tree[idx];
        int m = (lx + rx) >> 1;
        int a1 = calc(l, r, 2 * idx + 1, lx, m);
        int a2 = calc(l, r, 2 * idx + 2, m, rx);
        return min(a1, a2);
    }
 
    int calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
 
    void print() {
        for (int i = 0; i < 2 * size - 1; ++i) {
            cout << i << " " << tree[i] << endl;
        }
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
            cout << st.calc(l, r) << endl;
        }
    }
    return 0;
}
