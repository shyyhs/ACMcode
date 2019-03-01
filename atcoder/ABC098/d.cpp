#include<iostream>
#define ll long long
using namespace std;
int n;
ll a[300000];
ll ans=0;
ll s[30];
ll p[30];
bool check()
{
    for (int i=0; i<22; ++i)
        if (s[i]>1) return 0;
    return 1;
}

void add(int x,int flag)
{
    for (int i=0; i<22; ++i)
        s[i]+=flag*(((p[i])&x)>0);
}

void print()
{
    for (int i=0; i<5; ++i)
        cout<<s[i]<<' ';
    cout<<endl;
}
int main()
{
    p[0]=1;
    for (int i=1; i<22; ++i)
        p[i]=p[i-1]*2;
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%lld",&a[i]);
    ll start=0;
    for (int i=1; i<=n; ++i)
    {
        for (int j=start+1; j<=n; ++j)
        {
            add(a[j],1);
        //    print();
            if (check())
            {
                start=j;
            }else
            {
                add(a[j],-1);
                break;
            }
        }
        //cout<<i<<' '<<start<<endl;
        ans+=(start-i+1);
        add(a[i],-1);
    }
    cout<<ans<<endl;
    return 0;
}


