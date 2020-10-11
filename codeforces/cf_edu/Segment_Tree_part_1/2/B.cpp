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
        tree.assign(size << 1, 0);
    }

    void build(const vector<int> &a, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tree[idx] = a[lx];
            }
            return;
        }
        int m = (lx + rx) >> 1;
        build(a, 2 * idx + 1, lx, m);
        build(a, 2 * idx + 2, m, rx);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2]; 
    }

    void build(const vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] ^= 1;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m) {
            set(i, 2 * idx + 1, lx, m);
        } else {
            set(i, 2 * idx + 2, m, rx);
        }
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void set(int i) {
        set(i, 0, 0, size);
    }

    int find(int k, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) >> 1;
        if (k > tree[2 * idx + 1]) {
            k -= tree[2 * idx + 1];
            return find(k, 2 * idx + 2, m, rx);
        } else {
            return find(k, 2 * idx + 1, lx, m);
        }
    }

    int find(int k) {
        return find(k + 1, 0, 0, size);
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
        int op, k;
        cin >> op >> k;
        if (op == 1) {
            st.set(k);
        } else {
            cout << st.find(k) << endl;
        }
    }
    return 0;
}
