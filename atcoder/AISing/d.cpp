#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

int n,q;
ll a[200000];
ll qx[200000];;
ll sum1[200000];
ll sum2[200000];
ll s[200000];
ll s2[200000];

bool check(int leftIdx,int rightIdx,ll x)
{
    if (abs(x-a[leftIdx-1])>abs(a[rightIdx]-x) && 
    abs(x-a[rightIdx-1])>=abs(x-a[leftIdx]))
    {
        return 1;
    }else
    {
        return 0;
    }
}

int findR(int turnNum,ll x)
{
    int leftIdx,rightIdx;
    firstIdx = findx(x);
    for leftIdx
        rightIdx=leftIdx+turnNum-1;
        if (check(leftIdx,rightIdx,x)
                return rightIdx;
}


int findTurn(ll x)
{
    for a turnNum:
    {
        int rightMostIdx = findR(turnNum,x);
        if (n-rightMostIdx==turnNum)
        {
            return turnNum;
        }
    }
}

ll solve(ll x)
{
    ll ans=0;
    int lx,rx;
    int turnNum=0;
    turnNum = findTurn(x);

    lx=n-2*turnNum+1;
    rx=n-turnNum;
    ans+=s2[rx+1];
    ans+=s[lx-1];
    return ans;
}

int main()
{
    cin>>n>>q;
    for (int i=1; i<=n; ++i)
    {
        scanf("%lld",&a[i]);
        if (i&1) sum1[i]=((i==1)?0:sum1[i-2])+a[i];
        else sum2[i]=sum2[i-2]+a[i];
        s[i]=sum1[i]+sum2[i];
    }
    for (int i=1; i<=q; ++i)
    {
        scanf("%lld",&qx[i]);
    }
    for (int i=n; i>=1; --i)
    {
        s2[i]=s2[i+1]+a[i];
    }
    
    for (int i=1; i<=q; ++i)
    {
        printf("%lld\n",solve(qx[i]));
    }
    return 0;
}
