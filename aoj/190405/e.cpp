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
void work(int n,int x)
{
    int ans=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<i; ++j)
            for (int k=1; k<j; ++k)
                if (i!=k && k!=j && i+j+k==x)
                    ans+=1;
    cout<<ans<<endl;

}

int main()
{
    int n,x;
    while (1)
    {
        cin>>n>>x;
        if (x ==0 && n == 0) break;
        work(n,x);
    }

    return 0;
}

