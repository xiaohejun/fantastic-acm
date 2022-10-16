#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// #define on
#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x)
#endif

const int MAX_N = 1e5 + 100;
int a[MAX_N];
int b[MAX_N];
int aa[MAX_N];
int ans[MAX_N];
int revMin[MAX_N];

int merge(int *nums, int l, int mid, int r)
{
    int revPairNum = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    for (int i = 0; i < n1 + n2; ++i) {
        b[i] = nums[l + i];
    }

    dbg("---------------")
    // for (int i = l; i <= mid; ++i) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    // for (int i = mid + 1; i <= r; ++i) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    /*
    [0, n1) a
    [n1, n1 + n2) b
    */
    int i = 0;
    int j = n1;
    int tmpRevMin = MAX_N;
    for (int k = l; k <= r; ++k) {
        if (i >= n1) {
            nums[k] = b[j];
            ++j;
        } else if (j >= n1 + n2) {
            nums[k] = b[i];
            ++i;
        } else {
            // i < n1 and j < n1 + n2
            if (b[i] <= b[j]) {
                nums[k] = b[i];
                ++i;
            } else { // b[i] > b[j]
                // b[i]
                for (; k <= r; ++k) {
                    if (j < n1 + n2 && b[i] > b[j]) {
                        nums[k] = b[j];
                        tmpRevMin = min(tmpRevMin, b[j]);
                        ++j;
                        ++revPairNum;
                    } else {
                        --k;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n1; ++i) {
        revMin[b[i]] = min(revMin[b[i]], tmpRevMin);
    }
    // for (int i = l; i <= r; ++i) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    // for (int i = l; i <= r; ++i) {
    //     cout << revMin[nums[i]] << " ";
    // }
    // cout << endl;

    dbg("---------------")

    return revPairNum;
}

int reversePairs(int *nums, int l, int r)
{
    if (l >= r) {
        return 0;
    }

    int mid = (l + r) / 2;

    int revPairNum = 0;
    revPairNum += reversePairs(nums, l, mid);
    revPairNum += reversePairs(nums, mid + 1, r);
    revPairNum += merge(nums, l, mid, r);

    // dbg(l)
    // dbg(r)
    // dbg(revPairNum)
    return revPairNum;
}

int reversePairs(int *nums, int n)
{
    return reversePairs(nums, 0, n - 1);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        aa[i] = a[i];
        revMin[i] = i;
        ans[i] = 1;
    }
    ans[n] = 1;
    revMin[n] = n;
    
    int num = reversePairs(aa, n);

    // for (int i = 0; i < n; ++i) {
    //     cout << revMin[a[i]] << " ";
    // }
    // cout << endl;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(make_pair(-(a[i] - revMin[a[i]]), min(i + 2, n)));
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        ans[n - i] = v[i].second;
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
