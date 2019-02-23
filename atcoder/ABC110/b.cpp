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
int n,m,x,y,a[200],b[200];

bool check()
{
    return a[n]<b[0];
}
    

int main()
{
    cin>>n>>m>>x>>y;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    a[n]=x;
    for (int i=0; i<m; ++i)
        cin>>b[i];
    b[m]=y;
    sort(a,a+n+1);
    sort(b,b+m+1);
    if (check())
        cout<<"No War"<<endl;
    else cout<<"War"<<endl;
    return 0;
}

