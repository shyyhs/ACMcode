/*
ID: songskg2
PROG: humble
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
int n,m;
ll a[200];
ll s1[200];
int t1;
ll s2[400000];
int t2;
int l1[200],l2[200];


int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    ll lmt=2000000000;
    ll lmt2=2000;
    lmt=lmt*lmt2;

    cin>>n>>m;
    s1[0]=1;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        s1[i]=a[i];
    }
    t1=n+1;
//    for (int i=0; i<t1; ++i)
//        cout<<s1[i]<<' ';
//    cout<<endl;
    int rec=0;
    while (t2<=m)
    {
        
        ll minp=lmt;
        int ind,ind2;


        for (int j=1; j<=n; ++j)
        {
            ll ans1=lmt;
            ll ans2=lmt;
            if (l1[j]<t1)
            {
                ans1 = a[j]*s1[l1[j]];
            }
            if (l2[j]<t2)
            {
                ans2= a[j]*s2[l2[j]];
            }
            if (ans1<ans2)
            {
                if (ans1<minp) {minp=ans1; ind=j; ind2=1;}
            }else
            {
                if (ans2<minp) {minp=ans2; ind=j; ind2=2;}
            }
        }
        if (s2[t2-1]!=minp)
            s2[t2++]=minp;
        if (ind2==1)
            l1[ind]++;
        else l2[ind]++;
    }
    //for (int i=0; i<m; ++i)
    //    cout<<s2[i]<<' ';
    //cout<<endl;
    cout<<s2[m-1]<<endl;

    return 0;
}
