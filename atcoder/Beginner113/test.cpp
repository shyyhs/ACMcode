#include<iostream>
#include<algorithm>
using namespace std;
int n,m,w[900];
int X,Y;
int s=500;
int main()
{
    cin>>n>>m;
    cin>>X>>Y;
    int xmax=-1000;
    int ymin=1000;
    for (int i=0; i<n; ++i)
    {
        int x;
        cin>>x;
        w[s+x]=-1;
        xmax=max(xmax,x);
    }
    for (int i=0; i<m; ++i)
    {
        int x;
        cin>>x;
        w[s+x]=1;
        ymin=min(ymin,x);
    }
    if (xmax<ymin && xmax+1>=X && xmax+1<=Y)
        cout<<"No War";else cout<<"War"<<endl;
    
    return 0;
}
