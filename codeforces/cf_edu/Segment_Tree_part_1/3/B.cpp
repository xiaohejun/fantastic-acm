#include <iostream>
#include <vector>

using namespace std;

#define dbg(x) cout << __LINE__ << " : " << #x"=" << x << endl;

struct segtree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size << 1, 0); 
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
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void build(const vector<int> &a) {
        build(a, 0, 0, size);       
    }

    void set(int i, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            tree[idx] = 0;
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

    int get(int s, int idx, int lx, int rx) {
        if (rx - lx == 1) {
            return lx;
        }
        int mid = (lx + rx) >> 1;
        if (tree[2 * idx + 2] >= s) {
            return get(s, 2 * idx + 2, mid, rx);
        } else {
            return get(s - tree[2 * idx + 2], 2 * idx + 1, lx, mid);
        }
    }

    int get(int s) {
        return get(s, 0, 0, size);
    }

    void pt() {
        for (int i = 0; i < (size << 1) - 1; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    //freopen("../in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        v[i] = 1;
    }
    segtree st;
    st.init(n + 1);
    st.build(v);
    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        int x = st.get(a[i] + 1);
        st.set(x);
        ans.push_back(x);
    } 
    for (int i = n - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}