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

    void build(vector<int> &a, int idx, int lx, int rx) {
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

    void build(vector<int> &a) {
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

    int lower_bound(int x, int idx, int lx, int rx) {
        if (x > tree[idx]) {
            return -1;
        }
        if (rx - lx == 1) {
            return lx;
        }
        int mid = (lx + rx) >> 1;
        if (x <= tree[2 * idx + 1]) {
            return lower_bound(x, 2 * idx + 1, lx, mid);
        } else {
            return lower_bound(x, 2 * idx + 2, mid, rx);
        }
    }

    int lower_bound(int x) {
        return lower_bound(x, 0, 0, size);
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
            int x;
            cin >> x;
            cout << st.lower_bound(x) << endl;
        }
    }
    return 0;
}
