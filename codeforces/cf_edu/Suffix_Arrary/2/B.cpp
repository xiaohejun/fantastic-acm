#include <bits/stdc++.h>

using namespace std;

/*
1,3 2,3 4,1 4,2


*/

void radix_sort(vector<pair<pair<int, int>, int>> &a) {
    int n = a.size();
    // sort by second
    {
        vector<int> cnt(n, 0);
        for (auto x : a) {
            cnt[x.first.second]++;
        }
        // pos[i] 表示
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        for (auto x : a) {
            int i = x.first.second;
            a_new[pos[i]++] = x;
        }
        a = a_new;
    }
    // sort by first
    {
        vector<int> cnt(n, 0);
        for (auto x : a) {
            cnt[x.first.first]++;
        }
        // pos[i] 表示
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        for (auto x : a) {
            int i = x.first.first;
            a_new[pos[i]++] = x;
        }
        a = a_new;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    vector<int> p(n), c(n);
    vector<pair<char, int>> a(n);
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
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        radix_sort(a);
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
        k = k + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    return 0;
}