/*
ID: songskg2
PROG: fence6
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
int pflag[200][200];
int t;

int m,s,l,n1,n2;
bool tf[200];
int x,nowx,nowy;
int w[200][200];
int dst[200][200];

int check()
{
    for (int i=0; i<t; ++i)
    {
        bool flag=1;
        for (int j=0; j<200; ++j)
            if (pflag[i][j]!=tf[j])
            {
                flag=0;
                break;
            }
        if (flag==1) return i;
    }
    return -1;
}

int addpflag()
{
    for (int i=0; i<200; ++i)
        pflag[t][i]=tf[i];
    return t++;
}


int main()
{
    freopen("fence6.in","r",stdin);
    freopen("fence6.out","w",stdout);
    cin>>m;
    for (int i=1; i<=m; ++i)
    {
        cin>>s>>l>>n1>>n2;
        memset(tf,0,sizeof(tf));
        tf[s]=1;
        for (int j=1; j<=n1; ++j)
        {
            cin>>x;
            tf[x]=1;
        }
        if (check()>=0)
        {
            nowx=check();
        }else
        {
            nowx=addpflag();
        }
        memset(tf,0,sizeof(tf));
        tf[s]=1;
        for (int j=1; j<=n2; ++j)
        {
            cin>>x;
            tf[x]=1;
        }
        if (check()>-1)
        {
            nowy=check();
        }else
        {
            nowy=addpflag();
        }
        w[nowx][nowy]=l;
        w[nowy][nowx]=l;
    }
    for (int i=0; i<t; ++i)
        for (int j=0; j<t; ++j)
            if (w[i][j])
                dst[i][j]=w[i][j];
            else
                dst[i][j]=10000000;
//    for (int i=0; i<t; ++i)
//    {
//        for (int j=0; j<t; ++j)
//            cout<<w[i][j]<<' ';
//        cout<<endl;
//    }
    int ans=10000000;
    for (int k=0; k<t; ++k)
    {
        for (int i=0; i<k; ++i)
            for (int j=0; j<k; ++j)
                if (i!=j && w[k][i] && w[k][j])
                {
                    int tans=w[k][i]+dst[i][j]+w[j][k];
                    if (tans<ans)
                        ans=tans;
                }
        for (int i=0; i<t; ++i)
            for (int j=0; j<t; ++j)
                if (i!=j && j!=k && dst[i][k]+dst[k][j]<dst[i][j])
                    dst[i][j]=dst[i][k]+dst[k][j];
    }
    cout<<ans<<endl;
    


    return 0;
}
