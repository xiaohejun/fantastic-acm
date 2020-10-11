#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

struct segtree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while(size < n) size <<= 1;
        tree.assign(size << 1, -1);
    }

    void build(const vector<int> &a, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tree[idx] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) >> 1;
        build(a, 2 * idx + 1, lx, mid);
        build(a, 2 * idx + 2, mid, rx);
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void build(const vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] = v;
            return;
        }
        int mid = (lx + rx) >> 1;
        if (i >= mid) {
            set(i, v, 2 * idx + 2, mid, rx);
        } else {
            set(i, v, 2 * idx + 1, lx, mid);
        }
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }  

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int lower_bound(int x, int l, int idx, int lx, int rx) {
        if (x > tree[idx]) {
            return -1;
        }
        if (rx - lx == 1) {
            return lx;
        }
        int mid = (lx + rx) >> 1;
        int s1 = -1;
        if (l < mid) {
            s1 = lower_bound(x, l, 2 * idx + 1, lx, mid);
            if (s1 != -1) return s1;
        }
        return lower_bound(x, l, 2 * idx + 2, mid, rx);
    }

    int lower_bound(int x, int l) {
        return lower_bound(x, l, 0, 0, size);
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
            int x, l;
            cin >> x >> l;
            cout << st.lower_bound(x, l) << endl;
        }
    }
    return 0;
}
