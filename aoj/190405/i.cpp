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
using namespace std;
int n;
int a[500];
int f[400][400];
bool flag[400][400];

int c(int a,int b)
{
    if (a-b==1 || b-a==1 || a==b)
        return 1;
    return 0;
}

int dp(int l,int r)
{
    if (l>=r) return 0;
    if (r==l+1)
    {
        if (c(a[l],a[r]))
            return 2;
        return 0;
    }
    if (flag[l][r]) return f[l][r];
    flag[l][r]=1;
    int m=0;
    for (int i=l; i<r; ++i)
    {
        m=max(m,dp(l,i)+dp(i+1,r));
        if (c(a[i],a[i+1])==1)
        {
            for (int k=0; k<n; ++k)
            {
                if (i-k<l || i+1+k>r) break;
                m=max(m,k*2+dp(l,i-k)+dp(i+1+k,r));
                if (c(a[i-k],a[i+1+k])==0) 
                {
                    break;
                }
            }
        }
    }
    f[l][r]=m;
    return m;
}


void work()
{
    memset(f,0,sizeof(f));
    memset(flag,0,sizeof(flag));
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    cout<<dp(1,n)<<endl;
}

int main()
{
    while (1)
    {
        cin>>n;
        if (n==0) break;
        work();
    }

    return 0;
}

