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

    void set(int i, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] = 1;
            return;
        }
        int mid = (lx + rx) >> 1;
        if (i < mid) {
            set(i, 2 * idx + 1, lx, mid);
        } else {
            set(i, 2 * idx + 2, mid, rx);
        }
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void set(int i) {
        set(i, 0, 0, size);
    }

    int sum(int l, int r, int idx, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (l <= lx && rx <= r) return tree[idx];
        int mid = (lx + rx) >> 1;
        int s1 = sum(l, r, 2 * idx + 1, lx, mid);
        int s2 = sum(l, r, 2 * idx + 2, mid, rx);
        return s1 + s2;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main(){
    //freopen("../in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);
    vector<int> ans(n + 1, 0);
    segtree st;
    st.init(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        if (a[x] == -1) {
            a[x] = i;
        } else {
            ans[x] = i - a[x] - 1 - 2 * st.sum(a[x], i + 1);
            st.set(a[x]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
