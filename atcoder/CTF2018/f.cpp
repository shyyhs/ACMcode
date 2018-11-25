#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int w[350][350];
int c[350];
int d[350];
int n,m,k,r,p;
int top;
int out[350];
int flag[100010];
int maxl;

bool check(int *c,int k,int m)
{
    if (k==0 && m==0) return 1;
    if (k==0 && m>0) return 0;
    if (m==0 && k>0) return 0;
    memset(flag,0,sizeof(flag));
    return (dp(c,k,m,flag))
    for (int i=1; i<=n; ++i)
        if (c[i]==0)
        for (int j=maxl; j>=0; j--)
        {
            if (flag[j]>0 || j==0)
            {
                flag[j+d[i]]=max(flag[j+d[i]],flag[j]+1);
                if ((j+d[i]==k)&&flag[j+d[i]]==m) return 1;
            }
        }
    return 0;
}  

void getd(int now,int dpt)
{
    d[now]=dpt;
    for (int i=1; i<=w[now][0]; ++i)
        getd(w[now][i],dpt+1);
}

int main()
{
    cin>>n>>m>>k;
    for (int i=1; i<=n; ++i)
    {
        cin>>p;
        w[p][++w[p][0]]=i;
        if (p==0) r=i;
    }
    getd(r,1);
    for (int i=1; i<=n; ++i)
        maxl+=d[i];
    for (int i=1; i<=n; ++i)
    {
       if (k>=d[i])
       {
          int tmpk=k-d[i];
          int tc[350];
          int tm=m-1;
         for (int j=0; j<310; ++j)
             tc[j]=c[j];
         tc[i]=1;
         if (check(tc,tmpk,tm))
         {
             c[i]=1;
             k-=d[i];
             m--;
             out[top++]=i;
             if (m==0) break;
         }
       }
    }
    if (m||k) cout<<-1<<endl;
    else
        for (int i=0; i<top; ++i)
            cout<<out[i]<<' ';
    return 0;
}
