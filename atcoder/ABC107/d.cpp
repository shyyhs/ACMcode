#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
ll a[120000];
ll sa[120000];
ll na[120000];
ll s[120000];
ll totNum;
ll x;
ll ts[110000];

ll mergeSort(int l,int r)
{
    if (l>r) return 0;
    if (l==r) return (na[l]<0);
    ll ans=0;
    int mid=l+(r-l)/2;
    ans+=mergeSort(l,mid);
    ans+=mergeSort(mid+1,r);

    int t1=l; 
    int t2=mid+1;
    int t=0;
    while (t!=r-l+1)
    {
        if (s[t1]<=s[t2] || t2>r)
        {
            ts[t++]=s[t1++];
        }else
        {
            ans+=mid+1-t1;
            ts[t++]=s[t2++];
        }
    }
    for (int i=l; i<=r; ++i)
        s[i]=ts[i-l];
    return ans;
}

bool check(ll x)
{
    for (int i=1; i<=n; ++i)
        if (a[i]<x)
            na[i]=-1;
        else na[i]=1;
    s[0]=0;
    for (int i=1; i<=n; ++i)
        s[i]=s[i-1]+na[i];

    ll ans=mergeSort(1,n);
    return (ans<=totNum/2);

}



int main()
{

    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        totNum+=i;
        cin>>a[i];
        sa[i]=a[i];
    }
    sort(sa+1,sa+n+1);


    int l,r,mid;
    l=1; r=n;
    while (l<=r)
    {
        mid=l+(r-l+1)/2;
        int ans1=check(sa[mid]);
        int ans2=(check(sa[mid+1]));
        if (mid+1>n) ans2=0;
        //cout<<mid<<' '<<mid+1<<endl;
        //cout<<ans1<<' '<<ans2<<endl;
        //cout<<endl;
        if (ans1 && (!ans2))
        {
            cout<<sa[mid]<<endl;
            return 0;
        }
        if (ans1==0)
        {
            r=mid-1;
        }else if (ans2==1)
        {
            
            l=mid;
        }
    }
    return 0;
}

