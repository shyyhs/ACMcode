#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
ll k;
int n,m;
int state[110000];
int hasBlueAdj[110000];
bool allBlueAdj[110000];

struct T
{
    int y,next;
}e[300000];
int loc[110000];
int top=1;

void addEdge(int x,int y)
{
    e[top].y=y;
    e[top].next=loc[x];
    loc[x]=top++;
}
void printEdge()
{
    cout<<endl;
    for (int i=1; i<=n; ++i)
        for (int j=loc[i]; j; j=e[j].next)
            cout<<i<<' '<<e[j].y<<endl;
    cout<<endl;
}

bool allBlueAdjAdj(int i)
{
    for (int j=loc[i];j;j=e[j].next)
        if (allBlueAdj[e[j].y]==1)
            return 1;
    return 0;
}
void work()
{
    for (int i=1; i<=n; ++i)
    {
        if (k)
        {
            if (hasBlueAdj[i])
                cout<<"First"<<endl;
            else
                cout<<"Second"<<endl;
        }else
        { 
            if (allBlueAdjAdj(i))
                cout<<"First"<<endl;
            else cout<<"Second"<<endl;
        }
    }
}    

int main()
{
    int x,y;
    char c;
    memset(allBlueAdj,1,sizeof(allBlueAdj));
    scanf("%d %d %lld",&n,&m,&k);
    k=k%2;
    for (int i=1; i<=n; ++i)
    {
        scanf("%c",&c);
        while (c!='B' && c!='R') scanf("%c",&c);
        state[i]=(c=='B');
    }
    for (int i=1; i<=m; ++i)
    {
        scanf("%d %d",&x,&y);
        if (state[x]==1) hasBlueAdj[y]=1;
        if (state[y]==1) hasBlueAdj[x]=1;
        if (state[x]==0) allBlueAdj[y]=0;
        if (state[y]==0) allBlueAdj[x]=0;
        addEdge(x,y);
        addEdge(y,x);
    }
    work();
    return 0;
}
