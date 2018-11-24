#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
int n,k;
int a[1001];
ll ps[1001];
ll aa[1000090];
ll ta[1000090];

ll p2[45];
int top=0;
int t2=0;

int main()
{
    cin>>n>>k;
    for (int i=0; i<n; ++i)
    {
        cin>>a[i];
        if (i>0) ps[i]=ps[i-1]+a[i]; else ps[i]=a[i];
    }
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
        {
            if (j>i-1)
            {
                aa[top]= ps[j]-ps[i-1];
                top++;
            }
        }
    p2[0]=1;
    for (int i=1; i<45; ++i)
    {
        p2[i]=p2[i-1]*2;
    }
    for (int i=45; i>=0; --i)
    {
        t2=0;
        for (int j=0; j<top; ++j)
        {
            if (aa[j]&p2[i])
            {
                ta[t2++]=aa[j];
            }
        }
        if (t2>=k)
        {
            top=t2;
            for (int j=0; j<top; ++j)
                aa[j]=ta[j];
        }
    }
    for (int i=1; i<k; ++i)
    {
        aa[0]&=aa[i];
    }
    cout<<aa[0]<<endl;
        

    return 0;
}

