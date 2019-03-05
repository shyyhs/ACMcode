#include<iostream>
using namespace std;
int n,m,x,y,d;
int f[150000];
int dst[150000];

int find(int x)
{
    if (x==f[x])
    {
        return x;
    }else
    {
        int t1=f[x];
        int y=find(f[x]);
        dst[x]=dst[t1]+dst[x];
        f[x]=y;
        return f[x];
    }
}


int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        f[i]=i;
    bool flag=1;
    for (int i=1; i<=m; ++i)
    {
        scanf("%d%d%d",&x,&y,&d);
        if (flag==0) continue;
        if (find(x)==find(y))
        {
            flag=(dst[x]-dst[y]==d);
        }else
        {
            int t1=find(x),t2=find(y);
            f[t1]=t2;
            dst[t1]=d+dst[y]-dst[x];
        }

    }
    if (flag==0)
        cout<<"No"<<endl;
    else 
        cout<<"Yes"<<endl;
    return 0;
}
