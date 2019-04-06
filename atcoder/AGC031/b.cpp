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
#define ll long long
using namespace std;
ll M=1000000007;
int n;
int c[210000];
ll f1[210000];
ll f2[210000];
ll ans=0;

int nxt[210000];
int nxt2[210000];
int loc[210000];
int flag[210000];


int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&c[i]);
    }
    memset(loc,0,sizeof(loc));
    for (int i=n; i>=1; --i)
    {
        nxt[i]=loc[c[i]];
        loc[c[i]]=i;
    }
    memset(loc,0,sizeof(loc));
    for (int i=1; i<=n; ++i)
    {
        nxt2[i]=loc[c[i]];
        loc[c[i]]=i;
    }
    f1[0]=1;
    for (int i=1; i<=n; ++i)
    {
        f1[i]=f1[i-1];
        if (nxt2[i]>0 && nxt2[i]!=i-1)
            f1[i]+=f1[nxt2[i]];
        f1[i]%=M;
    }
    cout<<f1[n]<<endl;
    //f2[n+1]=1;
    //for (int i=n; i>=1; --i)
    //{
    //    f2[i]=f2[i+1];
    //    if (nxt[i]>0 && nxt[i]!=i+1)
    //        f2[i]+=f2[nxt[i]];
    //    f2[i]%=M;
    //}
    ////for (int i=1; i<=n; ++i)
    ////    cout<<i<<' '<<f2[i]<<endl;
    //for (int i=1; i<=n; ++i)
    //{
    //    int j=nxt[i];
    //    if (j==i+1) continue;
    //    if (j==0) continue;

    //    if (j>0)
    //    {
    //        cout<<i<<' '<<j<<' '<<f1[i]<<' '<<f2[j]<<endl;
    //        ans+=f1[i]*f2[j];
    //    }
    //    if (flag[i]==0)
    //    {
    //        //cout<<"there "<<i<<endl;
    //        //ans+=1;
    //    //    ans+=f1[i]*f2[i];
    //        for (int k=i; k<=j; ++k)
    //            flag[k]=1;
    //    }
    //    ans%=M;
    //} 
    //cout<<ans<<endl;

    return 0;
}

