#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;

int n;
int q;
int k;
char s[100010];
int pred[100010];
int prem[100010];
int prec[100010];

ll work(int k)
{
    int e=k-1;
    ll mc=0;
    ll ans=0;
    for (int i=0; i<e; ++i)
        if (s[i]=='M')
            mc+=prec[e]-prec[i];
    if (s[0]=='D') ans=mc;
    for (int i=1; i<n; ++i)
    {
        if (s[i]=='M')
            mc-=prec[min(n-1,i+e-1)]-prec[i];
        if (i+e<n && s[i+e]=='C')
        {
            mc+=prem[i+e]-prem[max(0,i-1)];
        }
        if (s[i]=='D')
            ans+=mc;
    }
    return ans;
}
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        scanf("%c",&s[i]);
        while (s[i]<'A' || s[i]>'Z')
            scanf("%c",&s[i]);
        if (i==0)
        {
            pred[i]+=(s[i]=='D');
            prem[i]+=(s[i]=='M');
            prec[i]+=(s[i]=='C');
        }else
        {
            pred[i]=pred[i-1]+(s[i]=='D');
            prem[i]=prem[i-1]+(s[i]=='M');
            prec[i]=prec[i-1]+(s[i]=='C');
        }
    }
    cin>>q;
    for (int i=0; i<q; ++i)
    {
        cin>>k;
        cout<<work(k)<<endl;
    }
    return 0;
}

