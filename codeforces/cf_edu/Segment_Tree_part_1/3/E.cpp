#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

struct segtree {
    int size;
    vector<LL> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size << 1, 0);
    }

    void set(int i, LL v, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] += v;
            return;
        }
        int mid = (lx + rx) >> 1;
        if (i < mid) {
            set(i, v, 2 * idx + 1, lx, mid);
        } else {
            set(i, v, 2 * idx + 2, mid, rx);
        }
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void set(int l, int r, int v) {
        set(l, v, 0, 0, size);
        set(r, -v, 0, 0, size);
    }

    LL sum(int l, int r, int idx, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (l <= lx && rx <= r) return tree[idx];
        int mid = (lx + rx) >> 1;
        LL s1 = sum(l, r, 2 * idx + 1, lx, mid);
        LL s2 = sum(l, r, 2 * idx + 2, mid, rx);
        return s1 + s2;
    }

    LL get(int i) {
        return sum(0, i + 1, 0, 0, size);
    }
};

int main(){
    //freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n + 1);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            LL v;
            cin >> l >> r >> v;
            st.set(l, r, v);
        } else {
            int i;
            cin >> i;
            cout << st.get(i) << endl;
        }
    }
    return 0;
}
