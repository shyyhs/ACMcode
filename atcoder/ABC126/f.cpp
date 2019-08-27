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

int m,k;

int main()
{
    cin>>m>>k;
    if (m==0)
    {
        if (k==0)
            cout<<0<<' '<<0<<endl;
        else
            cout<<-1<<endl;
    }
    if (m==1)
    {
        if (k==0)
            cout<<0<<' '<<1<<' '<<1<<' '<<0<<endl;
        else
            cout<<-1<<endl;
    }
    if (m>1)
    {
        if (k>=(1<<m))
            cout<<-1<<endl;
        else
        {
            for (int i=(1<<m)-1; i>=0; --i)
                if (i!=k)
                    cout<<i<<' ';
            cout<<k<<' ';
            for (int i=0; i<=(1<<m)-1; ++i)
                if (i!=k)
                    cout<<i<<' ';
            cout<<k<<endl;
        }
    }
    return 0;
}
