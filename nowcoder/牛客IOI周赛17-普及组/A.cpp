#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
const int MAX_N = 1e5+100;
int n, k;
LL sum[MAX_N];

namespace fastIO
{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define LL long long
    bool IOerror=0;
    inline char nc()
    {
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend)
        {
            p1=buf;
            pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1)
            {
                IOerror=1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch)
    {
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    inline void read(int &x)
    {
        bool sign=0;
        char ch=nc();
        x=0;
        for (; blank(ch); ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (; ch>='0'&&ch<='9'; ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(LL &x)
    {
        bool sign=0;
        char ch=nc();
        x=0;
        for (; blank(ch); ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (; ch>='0'&&ch<='9'; ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x)
    {
        bool sign=0;
        char ch=nc();
        x=0;
        for (; blank(ch); ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (; ch>='0'&&ch<='9'; ch=nc())x=x*10+ch-'0';
        if (ch=='.')
        {
            double tmp=1;
            ch=nc();
            for (; ch>='0'&&ch<='9'; ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    #undef LL
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;

int main(){
    freopen("in.txt", "r", stdin);
    read(n);
    read(k);
    int x;
    sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        read(x);
        sum[i] = sum[i-1] + x;
    }
    int l, r;
    while(k--){
        read(l);
        read(r);
        printf("%lld\n", sum[r] - sum[l-1] );
    }
    return 0;
}
