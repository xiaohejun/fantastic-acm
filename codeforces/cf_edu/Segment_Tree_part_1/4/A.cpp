#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;

struct Segtree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size << 1, 0);
    }

    void f(int &a, int b, int c, int op) {
        if (op & 1) {
            a = b - c;
        } else {
            a = b + c;
        }
    }

    int build(const vector<int> &a, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tree[idx] = a[lx];
            }
            return 1;
        }
        int mid = (lx + rx) >> 1;
        int lRet = build(a, 2 * idx + 1, lx, mid);
        int rRet = build(a, 2 * idx + 2, mid, rx);
        f(tree[idx], tree[2 * idx + 1], tree[2 * idx + 2], lRet);
        return 0;
    }

    void build(const vector<int> &a) {
        (void)build(a, 0, 0, size);
    }

    int set(int i, int v, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] = v;
            return 1;
        }
        int mid = (lx + rx) >> 1;
        int op = 0;
        if (i < mid) {
            op = set(i, v, 2 * idx + 1, lx, mid);
        } else {
            op = set(i, v, 2 * idx + 2, mid, rx);
        }
        f(tree[idx], tree[2 * idx + 1], tree[2 * idx + 2], op);
        return 0;
    }

    void set(int i, int v) {
        (void)set(i, v, 0, 0, size);
    }

    int calc(int l, int r, int idx, int lx, int rx, int &op) {
        if (rx <= l || lx >= r) {
            op = 0;
            return 0;
        }
        if (l <= lx && rx <= r) {
            op = rx - lx;
            return tree[idx];
        }
        int opL, opR;
        int mid = (lx + rx) >> 1;
        int lRet = calc(l, r, 2 * idx + 1, lx, mid, opL); 
        int rRet = calc(l, r, 2 * idx + 2, mid, rx, opR);
        op = opL + opR;
        int ret = 0;
        f(ret, lRet, rRet, opL);
        return ret;
    }

    int calc(int l, int r) {
        int op;
        return calc(l, r, 0, 0, size, op);
    }

    void pt() {
        for (int i = 0; i < (size << 1) - 1; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    //freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Segtree st;
    st.init(n);
    st.build(a);
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 0) {
            int i, j;
            cin >> i >> j;
            st.set(i - 1, j);
        } else if (op == 1) {
            int l, r;
            cin >> l >> r;
            cout << st.calc(l - 1, r) << endl;
        }
    }
    return 0;
}
