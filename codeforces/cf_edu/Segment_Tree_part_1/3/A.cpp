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
        tree.assign(size << 1, 0);
    }

    void set(int i, int v, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] = v;
            return ;
        }
        int mid = (lx + rx) >> 1;
        if (i < mid) {
            set(i, v, 2 * idx + 1, lx, mid);
        } else {
            set(i, v, 2 * idx + 2, mid, rx);
        }
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int idx, int lx, int rx) {
        if (rx <= l || lx >= r) return 0;
        if (lx >= l && rx <= r) return tree[idx];
        int mid = (lx + rx) >> 1;
        int s1 = sum(l, r, 2 * idx + 1, lx, mid);
        int s2 = sum(l, r, 2 * idx + 2, mid, rx);
        return s1 + s2;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    void pt() {
        for (int i = 0; i < (size << 1) - 1; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    //freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    segtree st;
    st.init(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = st.sum(a[i], n);
        st.set(a[i] - 1, 1);
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
