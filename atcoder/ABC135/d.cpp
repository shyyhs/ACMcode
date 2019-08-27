#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;
ll M=1000000007;
char s[200000];
char c;
int t=0;

int top=0;
int a[200000];

ll f[200000][20];
bool flag[200000][20];

ll dp(int now,int r)
{
    if (now>top)
    {
        if (r==0) return 1;
        else return 0;
    }
    if (flag[now][r]) return f[now][r];
    flag[now][r]=1;
    
    for (int i=0; i<=9; ++i)
    {
        ll num = (a[now]*i)%13;
        ll nextr = (r-num+26)%13;
        f[now][r] = (f[now][r] + dp(now+1,nextr))%M;
    }

    return f[now][r];
}

int main()
{
    while (1)
    {
        scanf("%c",&c);
        if ((c>='0' && c<='9') || (c=='?'))
        {
            t++;
            s[t] = c;
        }else
            break;
    }
    for (int i=1; i<=(1+t)/2; ++i)
        swap(s[i],s[t-i+1]);
   // for (int i=1; i<=t; ++i)
   //     cout<<s[i];
   // return 0;
    ll now=0;
    ll totnum=0;
    for (int i=1; i<=t; ++i)
    {
        if (i==1) now=1;
        else now=(now*10)%13;

        if (s[i]!='?')
        {
            int num=(s[i]-'0');
            totnum = (totnum + now*num)%13;
        }else
        {
            top++;
            a[top] = now;
        }
    }

    totnum = 5-totnum;
    while (totnum<0) totnum+=13;
    //cout<<totnum<<endl;
    //for (int i=1; i<=top; ++i)
    //    cout<<a[i]<<' ';
    //cout<<endl;
    ll ans=0;
    ans=(ans + dp(1,totnum))%M;
    cout<<ans<<endl;


    return 0;
}

