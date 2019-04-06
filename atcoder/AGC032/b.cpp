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
using namespace std;
int n;

int main()
{
    cin>>n;
    if (n%2==0)
    {
        cout<<n*(n-2)/2<<endl;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                if (i<j && i+j!=n+1)
                {
                    cout<<i<<' '<<j<<endl;
                }
    }else
    {
        cout<<n-1+(n-1)*(n-3)/2<<endl;
        for (int i=1; i<=n-1; ++i)
            for (int j=1; j<=n-1; ++j)
                if (i<j && i+j!=n)
                {
                    cout<<i<<' '<<j<<endl;
                }
        for (int i=1; i<=n-1; ++i)
            cout<<i<<' '<<n<<endl;
    }
    return 0;

}
