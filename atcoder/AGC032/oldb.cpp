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
int f[200][10010];
int p[200][10010];
int pa[200][10010];
bool flag[10000];


int t=0;
struct node
{
    int x,y;
};
node ansn[20000];
bool cmp(node a,node b)
{
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
int outFlag[20000];
int finalT=0;
int ans=0;

bool w[101][101];
bool wflag[101];
void flow(int x)
{
    wflag[x]=1;
    for (int i=1; i<=n; ++i)
        if (w[x][i] && wflag[i]==0)
            flow(i);
}
void printw()
{

    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
            cout<<w[i][j]<<' ';
        cout<<endl;
    }
}
bool check(int s)
{
    memset(w,0,sizeof(w));
    memset(wflag,0,sizeof(wflag));
    for (int i=1; i<=n; ++i)
    {
        int tans=s;
        while (tans)
        {
            w[i][pa[i][tans]]=1;
            tans=p[i][tans];
        }
    }
    if (s>5)
    {
        cout<<s<<endl;
        printw();
    }
    flow(1);
    for (int i=1; i<=n; ++i)
        if (wflag[i]==0)
            return 0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (w[i][j]!=w[j][i])
                return 0;
    return 1;
}


int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        f[i][0]=1;
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
            if (i!=j)
                for (int k=5500; k>=j; --k)
                    if (f[i][k-j])
                    {
                        f[i][k]=1;
                        p[i][k]=k-j;
                        pa[i][k]=j;
                    }
    }
    for (int i=1; i<=5500; ++i)
    {
        flag[i]=1;
        for (int j=1; j<=n; ++j)
            if (f[j][i]==0)
            {
                flag[i]=0;
                break;
            }
        if (flag[i]==1)
            cout<<i<<endl;
        if (flag[i]==1 && check(i))
        {
            ans=i;
            break;
        }
    }
    for (int i=1; i<=n; ++i)
    {
        int tans=ans;
        while (tans)
        {
                ansn[t].x=i;
                ansn[t].y=pa[i][tans];
                t++;
            tans=p[i][tans];
        }
    }
    for (int i=0; i<t; ++i)
    {
        if (ansn[i].x>ansn[i].y)
        {
            int tmp=ansn[i].x;
            ansn[i].x=ansn[i].y;
            ansn[i].y=tmp;
        }
    }
    sort(ansn,ansn+t,cmp);
    finalT=0;
    for (int i=0; i<t; ++i)
    {
        outFlag[i]=1;
        if (ansn[i].x==ansn[i+1].x && ansn[i].y==ansn[i+1].y)
        {
            outFlag[i]=0;
        }
        finalT+=outFlag[i];
    }
    cout<<(finalT)<<endl;
    for (int i=0; i<t; ++i)
    {
        if (outFlag[i])
            printf("%d %d\n",ansn[i].x,ansn[i].y);
    }
    return 0;
}

