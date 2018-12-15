#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool p[1000];
int n=1000;

int main()
{
    memset(p,1,sizeof(p));
    for (int i=0; i<n; ++i)
    {
        if (i<2) p[i]=0;
        if (p[i]==0) continue;
        if (p[i]==1)
            for (int j=i*2; j<n; j+=i)
                p[j]=0;
    }
    for (int i=0; i<100; ++i)
        if (p[i])
            cout<<i<<endl;
    return 0;
}
