#include<iostream>
#include<cstdio>
using namespace std;
int maxN=55555;
int n;
bool p[60000];

void init()
{
    for (int i=2; i<=maxN; ++i)
        if (p[i]==0)
            for (int j=2; i*j<=maxN; ++j)
                p[i*j]=1;
}


int main()
{
    cin>>n;
    init();
    for (int i=2; i<=maxN; ++i)
        if (p[i]==0 && (i%5==1))
        {
            cout<<i<<' ';
            n--;
            if (n==0) break;
        }
    return 0;
}
