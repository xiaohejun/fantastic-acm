#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

const int MAX_N = 35;
int a[MAX_N];
int chg[26];

inline int idx(char c)
{
    return c - 'a';
}

inline int toCh(int x)
{
    return 'a' + x;
}

void calcStep(char c, int k, char &beC, int &need)
{
    char curC = toCh(chg[idx(c)]);
    int step = idx(curC);
    if (k >= step) {
        need = step;
        beC = 'a';
    } else {
        need = k;
        beC = (char)(curC - k);
    }
}

void updChg(char c, char beC)
{
    for (int i = idx(c); i >= idx(beC); --i) {
        chg[i] = idx(beC);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // if (k >= 25) {
    //     for (int i = 0; i < n; ++i) {
    //         cout << 'a';
    //     }
    //     cout << endl;
    //     return;
    // }
    dbg(s)
    dbg(k)
    for (int i = 0; i < 26; ++i) {
        chg[i] = i;
    }
    int curK = k;
    char lstBeC = '#';
    char lstC = '#';
    int lstNeed = 0;
    bool needLst = true;
    for (int i = 0; i < n; ++i) {
        if (curK == 0) {
            break;
        }
        char beC;
        int need;
        calcStep(s[i], curK, beC, need);

        if (needLst) {
            lstC = s[i];
            lstBeC = beC;
            lstNeed = need;
            needLst = false;
            // todo_h
            if (i != n - 1) {
                continue;
            }
        }
        dbg(lstC)
        dbg(lstBeC)
        dbg(lstNeed)
        // cout << s[i] << " -> " << beC << " " << need << endl;
        bool c1 = (i != 0 && !((s[i] >= lstC) && (beC <= lstBeC)));
        bool c2 = (i == n - 1);
        if (c1 || c2) {
            dbg("stop")
            // 停止了
            curK -= lstNeed;
            updChg(lstC, lstBeC);
            if (i != n - 1) {
                --i;
            }
            needLst = true;
            continue;
        }

        lstC = s[i];
        lstBeC = beC;
        lstNeed = need;
        // lstC = s[i];
        // lst
    }

    for (int i = 0; i < n; ++i) {
        char curC = toCh(chg[idx(s[i])]);
        cout << curC;
    }
    cout << endl;
}

/*
x -> y


所有<=x的都能变成y，除了'z' -> 'a'
*/

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*
4 5
fgde

f->e
e->d
d->c
c->b
b->a

a b c d e f g
*/
