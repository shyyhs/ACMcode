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

int s[20];
int ans=10000000;
int a[100];
int l[100];

int myabs(int a)
{
    if (a<0) return -a;
    return a;
}
void prints()
{
    for (int i=1; i<=n; ++i)
        cout<<s[i]<<' ';
    cout<<endl;
}
void check()
{
    int num[4]={0,0,0,0};
    int sumL[4]={0,0,0,0};
    int tans=0;
    for (int j=1; j<=n; ++j)
    {
        num[s[j]]+=1;
        sumL[s[j]]+=l[j];
    }
    for (int j=1; j<=3; ++j)
    {
        if(num[j]==0) return;
        tans+=10*(num[j]-1);
    }
    for (int j=1; j<=3; ++j)
        tans+=myabs(sumL[j]-a[j]);
    if (tans<ans) 
    {
//        prints();
        ans=tans;
    }
}

void dfs(int now)
{
    if (now==n+1)
    {
        check();
    }else
    {
        for (int i=0; i<=3; ++i)
        {
            s[now]=i;
            dfs(now+1);
        }
    }
}

int main()
{
    cin>>n;
    for (int i=1; i<=3; ++i)
        cin>>a[i];
    for (int i=1; i<=n; ++i)
        cin>>l[i];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

