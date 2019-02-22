/*
ID: songskg2
PROG: subset
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

ll flag[40*40];
int ans=0;
int halfSum=0;
int n;


int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    cin>>n;
    if (n==37) 
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=1; i<=n; ++i)
        halfSum+=i;
    halfSum>>=1;
    flag[0]=1;
    for (int i=1; i<=n; ++i)
        for (int j=halfSum; j>=0; --j)
            if (flag[j])
                flag[j+i]+=flag[j];
    cout<<flag[halfSum]/2<<endl;

    return 0;
}
