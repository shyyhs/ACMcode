/*
ID: songskg2
PROG: nocows
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;
int M=9901;
ll oneT[300][120];
bool flagOne[300][120];
int n,k;

bool flag[300][300];
ll f[300][300];

ll dp(int num,int ht)
{
    if (((num+1)>>1)<ht) return 0;
    if (ht==1)
    {
        if (num==1) return 1;
        return 0;
    }

    if (flagOne[num][ht]) return oneT[num][ht];
    flagOne[num][ht]=1;

    for (int i=1; i<=num-2; ++i)
    {
        oneT[num][ht]+=dp(i,ht-1)*dp(num-1-i,ht-1);
        for (int k=1; k<ht-1; ++k)
        {
            oneT[num][ht]+=dp(i,k)*dp(num-1-i,ht-1);
            oneT[num][ht]+=dp(i,ht-1)*dp(num-1-i,k);
        }
    }
    if (oneT[num][ht]>1000000) oneT[num][ht]%=M;
    //oneT[num][ht]%=M;
    //cout<<num<<' '<<ht<<' '<<oneT[num][ht]<<endl;
    return oneT[num][ht];
}

ll dp2(int now,int minx)
{
    if (flag[now][minx]) return f[now][minx];
    if (now==n+1) return 1;
    if (n-now+1<minx) return 0;
    flag[now][minx]=1;
    for (int i=minx; i<=n-now+1; ++i)
        f[now][minx]+=dp(i,k)*dp2(now+i,i);
    return (f[now][minx]%=M);
}

    


int main()
{
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    cin>>n>>k;
    cout<<dp(n,k)%M<<endl;
//    cout<<dp2(1,1)<<endl;
    return 0;
}
