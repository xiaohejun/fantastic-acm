#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << __LINE__ << " : " << #x"=" << x << endl;

void count_sort(vector<int> &p, vector<int> c) {
    int n = p.size();
    vector<int> cnt(n);
    for (int x : p) {
        cnt[c[x]]++;
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
    freopen("../in.txt", "r", stdin);
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    vector<pair<char, int>> a(n);
    vector<int> c(n), p(n);
    for (int i = 0; i < n; ++i) {
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i].first == a[i-1].first) {
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

    for (int i = 0; i < n; ++i) {
        cout << p[i] << " " << c[i] << endl;
    }

    return 0;
}

/*
c[0] = 2
表示
*/