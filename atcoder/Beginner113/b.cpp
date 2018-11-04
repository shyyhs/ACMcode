#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int t,a;
int h[2000];
double clo=10000000;
int ind=0;
void init()
{
    cin>>n>>t>>a;
    for (int i=1; i<=n; ++i)
    {
        cin>>h[i];
        if (abs(a-(t-h[i]*0.006))<clo)
        {
            clo=abs(a-(t-h[i]*0.006));
            ind=i;
        }
    }
    cout<<ind<<endl;
}
void work()
{


}

int main()
{
    init();
    work();
    return 0;
}


