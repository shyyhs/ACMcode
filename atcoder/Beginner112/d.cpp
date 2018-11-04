#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<random>
using namespace std;

int n,m;
void init()
{
    scanf("%d %d",&n,&m);
}

void work()
{
    int ans=1;
    for (int i=1; i<=sqrt(m); ++i)
        if (m%i==0)
        {
            if (m/i>=n)
                ans=max(ans,i);
            if (i>=n)
                ans=max(ans,m/i);
        }
    cout<<ans<<endl;
}


int main()
{
    init();
    work();

    return 0;
}

