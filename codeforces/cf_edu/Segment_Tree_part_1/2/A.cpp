#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const LL INF = 1LL << 60;

struct item {
    LL seg, pre, suf, sum;
};

struct segtree {
    int size;
    vector<item> tree;
    const item NEUTRAL_ITEM = {-INF, -INF, -INF, 0};
    
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(size << 1, NEUTRAL_ITEM);
    }

    item merge(item a, item b) {
        item c;
        c.seg = max({a.seg, b.seg, a.suf + b.pre});
        c.pre = max({a.pre, a.sum + b.pre});
        c.suf = max({b.suf, b.sum + a.suf});
        c.sum = a.sum + b.sum;
        return c;
    }

    void build(vector<LL> &a, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tree[idx] = (item){a[lx], a[lx], a[lx], a[lx]};
            }
            return;
        }
        int m = (lx + rx) >> 1;
        build(a, 2 * idx + 1, lx, m);
        build(a, 2 * idx + 2, m, rx);
        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void set(int i, LL v, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] = (item){v, v, v, v};
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m) {
            set(i, v, 2 * idx + 1, lx, m);
        } else {
            set(i, v, 2 * idx + 2, m, rx);
        }
        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void set(int i, LL v) {
        set(i, v, 0, 0, size);
    }

    void build(vector<LL> &a) {
        build(a, 0, 0, size);
    }

    item max_segment(int l, int r, int idx, int lx, int rx) {
        if (r <= lx || l >= rx) return NEUTRAL_ITEM;
        if (l <= lx && rx <= r) return tree[idx];
        int m = (lx + rx) >> 1;
        item s1 = max_segment(l, r, 2 * idx + 1, lx, m);
        item s2 = max_segment(l, r, 2 * idx + 2, m, rx);
        return merge(s1, s2);
    }

    item max_segment(int l, int r) {
        return max_segment(l, r, 0, 0, size);
    }
};

int main(){
    //freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    st.build(a);
    item it = st.max_segment(0, n);
    cout << max(0LL, it.seg) << endl; 
    while (m--) {
        int i;
        LL v;
        cin >> i >> v;
        st.set(i, v);
        it = st.max_segment(0, n);
        cout << max(0LL, it.seg) << endl;
    }
    return 0;
}
