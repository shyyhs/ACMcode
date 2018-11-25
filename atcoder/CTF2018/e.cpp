#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define M 1000000007
#define ll long long
using namespace std;

int n;
int a[500];
ll f[400][1500];
bool flag[400][1500];
/*
ll dp(int loc, int num)
{
    5 3 10
    2 0 2 1 4
    if (flag[loc][num]) return f[loc][num];
    if (num>1000) f[loc][num]=0;
    else if (num==0) f[loc][num]=1;
    else if (loc==1) {f[loc][num]=(a[loc]>=num)?1:0;}
    else
    {
        for (int i=0; i<=min(a[loc],num); ++i)
            f[loc][num]=(f[loc][num]+dp(loc-1,(num-i)*2))%M;
    }
    flag[loc][num]=1;
    return f[loc][num];
}
*/
int main()
{
    ll ans=0;
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=1; i<390; ++i)
    {
        for (int j=0; j<700; ++j)
        {
            if (i==1) 
            {
                if (a[i]>=j) f[i][j]=1;
                else f[i][j]=0;
            }else
            if (j==0)
                f[i][j]=1;
            else
            {
                for (int k=0; k<=min(a[i],j); ++k)
                    f[i][j]=(f[i][j]+f[i-1][(j-k)*2])%M;
            }
        }
    }
    for (int i=1; i<=390; ++i)
    {
        ans=(ans+f[i][1])%M;
    }
    cout<<ans<<endl; 
    return 0;
}
