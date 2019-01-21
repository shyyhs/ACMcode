#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
ll M=1000000007;
ll minNum=10000000;
ll MAXN=1200000;

ll ans=1;
ll a[20000];
ll b[20000];
bool row[20000];
bool col[20000];

struct T
{
    ll num,r,c;
} s[100000];
int tot=0;

ll fac[1200000];
ll rev[1200000];
int n,m;
void exgcd(ll a,ll b,ll &x, ll &y)
{
    if (!b)
    {
        x=1;
        y=0;
        return;
    }
    ll x0,y0;
    exgcd(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
}

ll fastpow(int n,int k)
{
    ll ans=1,tmp=n;
    while (k)
    {
        if (k&1) ans*=tmp,ans%=M;
        tmp=(tmp*tmp)%M;
        k>>=1;
    }
    return ans;
}
void combRev()
{
    fac[0]=1;
    for (int i=1; i<=MAXN; ++i)
        fac[i]=(fac[i-1]*i)%M;
    rev[MAXN] = fastpow(fac[MAXN],M-2);
    for (int i=MAXN-1; i>=0; --i)
        rev[i]=(rev[i+1]*(i+1))%M;
}


bool cmp(T a,T b)
{
    return a.num<b.num;
}

ll A(ll x,ll y)
{
    if (y>x) return 0;
    return ((fac[x]*rev[x-y])%M);
}

int main()
{
    combRev();

    cin>>n>>m;
    ll colNum=m;
    ll rowNum=n;
    bool flagg=1;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        for (int j=0; j<tot; ++j)
            if (s[j].num==a[i])
            {
                flagg=0;
            }
        s[tot].num=a[i];
        s[tot].r=i;
        tot++;
    }
    for (int i=1; i<=m; ++i)
    {
        cin>>b[i];
        bool flag=0;
        for (int j=0; j<tot; ++j)
            if (s[j].num==b[i])
            {
                if (s[j].c!=0)
                {
                    flagg=0;
                }
                s[j].c=i;
                flag=1;
                break;
            }
        if (flag==0)
        {
            s[tot].num=b[i];
            s[tot].c=i;
            tot++;
        }
    }
    if (flagg==0)
    {
        cout<<0<<endl;
        return 0;
    }

    sort(s,s+tot,cmp);


    int now=0;
    for (int i=0; i<tot; ++i)
    {
        if (s[i].r>0 && s[i].c>0)
        {
            ll t = (A(s[i].num-now-1,colNum-1+rowNum-1))%M;
            ans= ans*t %M;
            now+=(colNum-1+rowNum-1+1);
            colNum--;
            rowNum--;
        }else
        if (s[i].r>0 && s[i].c==0)
        {
            ll t = (A(s[i].num-now-1,colNum-1))%M;
            ans= ans *t %M;
            ans= ans*colNum%M;
            now+=(colNum);
            rowNum--;
        }else 
        if (s[i].c>0 && s[i].r==0)
        {
            ll t = (A(s[i].num-now-1,rowNum-1))%M;
            ans = ans *t %M;
            ans = ans*rowNum%M;
            now+=rowNum;
            colNum--;
        }
    }
    cout<<ans<<endl;        

    



    return 0;
}
