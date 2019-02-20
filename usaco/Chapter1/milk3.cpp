/*
ID: songskg2
PROG: milk3
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
bool flag[20*20*40];
int a[3];
int s[3];
bool c[21];

int hs()
{
    return s[0]*20*20+s[1]*20+s[2];
}
void prints()
{
    for (int i=0; i<3; ++i)
        cout<<s[i]<<' ';
    cout<<endl;
}
void dfs()
{
    if (flag[hs()])
    {
        return;
    }else
    {
        flag[hs()]=1;
        if (s[0]==0)
        c[s[2]]=1;
        for (int i=0; i<3; ++i)
            for (int j=0; j<3; ++j)
                if (i!=j)
                {
                    int t=min(s[i],a[j]-s[j]);
                    s[i]-=t;
                    s[j]+=t;
                    dfs();
                    s[i]+=t;
                    s[j]-=t;
                }
    }
}


int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    for (int i=0; i<3; ++i)
        cin>>a[i];
    s[2]=a[2];
    dfs();
    int ind;
    for (ind=20; ind>=0 && c[ind]==0; --ind);
    for (int i=0; i<=ind; ++i)
    {
        if (c[i])
        {
            cout<<i;
            if (i!=ind) cout<<' ';
        }
    }
    cout<<endl;
    return 0;
}
