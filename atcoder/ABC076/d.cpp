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
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;
int n;
double t[200];
double v[200];
double vt[200];

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>t[i];
    for (int i=1; i<=n; ++i)
        cin>>v[i];
    for (int i=n; i>=1; --i)
        vt[i]=min(v[i],vt[i+1]+t[i]);
    double nowv=0;
    double d=0;
    for (int i=1; i<=n; ++i)
    {
       if (nowv+t[i]<vt[i+1])
       {
           d+=t[i]*(nowv+nowv+t[i])/2;
           nowv+=nowv+t[i];
       }else if(nowv>vt[i+1])
       {
           double h=nowv-vt[i+1];
           d+=(t[i]-h+t[i])*h/2+t[i]*vt[i+1];
           nowv=vt[i+1];
       }else if (t[i]>=v[i]-nowv+v[i]-vt[i])
       {
           double h1=v[i]-nowv;
           double h2=v[i]-vt[i];
           d+=h1*


    return 0;
}

