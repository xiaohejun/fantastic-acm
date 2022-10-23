#ifndef DEBUG_H
#define DEBUG_H

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned int x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '('; __print(x.first); cout << ", "; __print(x.second); cout << ')';}

template<typename T>
void __print(const T &x) {int f = 0; cout << '['; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "]";}

void _print() {cout << "\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
    #define dbg(x...) cout << "[line " << __LINE__ << "]: " << #x << " = "; _print(x);
#else
    #define dbg(x...)
#endif

#endif