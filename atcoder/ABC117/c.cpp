#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
int n,m;
int x[120000];
int b[120000];
int t=0;
int ans;

bool cmp(int a,int b)
{
    return a>b;
}



int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; ++i)
        scanf("%d",&x[i]);
    sort(x,x+m);
    for (int i=1; i<m; ++i)
        b[t++]=x[i]-x[i-1];
    sort(b,b+t,cmp);
    int ans=x[m-1]-x[0];
    for (int i=0; i<(n-1); ++i)
        ans-=b[i];
    cout<<ans<<endl;
    return 0;
}
