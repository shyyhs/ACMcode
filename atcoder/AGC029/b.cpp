#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<ctime>
#include<random>
#include<set>
#include<map>
#define ll long long
using namespace std;
int n;
ll a[300000];
ll t[50];
map<ll,int> s1;


void init()
{
    t[0]=1;
    for (int i=1; i<40; ++i)
        t[i]=t[i-1]*2;
}

bool cmp(ll a,ll b)
{
    return (a>b);
}

int main()
{
    init();
    int an=0;
    cin>>n;
    for (int i=0; i<n; ++i)
        scanf("%lld",&a[i]);
    sort(a,a+n,cmp);
    for (int i=0; i<n; ++i)
    {
        bool flag=0;
        for (int j=32; j>=1; --j)
            if (s1.find(t[j]-a[i])!=s1.end() &&((s1[t[j]-a[i]])>0) )
            {
                s1[t[j]-a[i]]-=1;
                flag=1;
                an++;
                break;
            }
        if (!flag)
        {
            if (s1.find(a[i])!=s1.end())
            s1[a[i]]+=1;else s1[a[i]]=1;
        }
    }
    cout<<an<<endl;

    return 0;
}
