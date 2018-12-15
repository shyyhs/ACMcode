#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
#define N 10000000
bool p[N];
int n=N;

void init()
{
    memset(p,1,sizeof(p));
    for (int i=0; i<=sqrt(n); ++i)
    {
        if (i<2) p[i]=0;
        if (p[i]==0) continue;
        if (p[i]==1)
            for (int j=i*2; j<n; j+=i)
                p[j]=0;
    }
}

void p1_5()
{
    int sum=0;
    int part=0;
    for (int i=0; i<n; ++i)
    {
        if (p[i]) sum++;
        if (p[i] && (((i+1)%4)==0)) part++;
    }
    cout<<sum<<' '<<N/log(N)<<endl;
    cout<<sum<<' '<<part<<endl;
}


int main()
{
    init();
    p1_5();
    return 0;
}
