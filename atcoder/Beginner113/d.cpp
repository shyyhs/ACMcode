#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;
int n,m,k;
int tot;
long long ans=0;
long long MOD=1000000007;

void init()
{
    cin>>n>>m>>k;
}
long long rpow(long long a, long long b)
{
    long long ans=1;
    for (int i=1; i<=b; ++i)
        ans=(ans*a)%MOD;
    return ans;
}

void work()
{
    tot=(m-1)*n; 
    if (k-1>n)
    {
        cout<<0<<endl;
        return 0;
    }
    int remain=n-(k-1);
            //a in first line b in last line
            //rpow(2,tot+a+b-2*(n-1+k-1));
            //only need k-1+k-1-1 totally k-1+n-1

}

int main()
{
    init();
    work();
    return 0;
}


