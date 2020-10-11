#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << __LINE__ << " : " << #x"=" << x << endl;

void count_sort(vector<int> &p, const vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);
    for (int x : c) {
        cnt[x]++;
    }
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; ++i) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    vector<int> p_new(n);
    for (int x : p) {
        p_new[pos[c[x]]++] = x;
    }
    p = p_new;
}

int main() {
    //freopen("../in.txt", "r", stdin);
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; ++i) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    vector<int> p(n), c(n);
    for (int i = 0; i < n; ++i) {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i].first == a[i - 1].first) {
            c[p[i]] = c[p[i - 1]];
        } else {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; ++i) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p, c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (prev == now) {
                c_new[p[i]] = c_new[p[i - 1]];
            } else {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        ++k;
    }

    vector<int> lcp(n);
    k = 0;
    for (int i = 0; i < n - 1; ++i) {
        int pi = c[i];
        int j = p[pi - 1];
        while (s[i + k] == s[j + k]) ++k;
        lcp[pi] = k;
        k = max(0, k - 1);
    }
    LL ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += n - 1 - p[i] - lcp[i];
    }
    cout << ans << endl;
    return 0;
}