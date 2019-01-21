#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int minM=1000000;
int X;
int ans=0;
int main()
{
    cin>>n>>X;
    for (int i=0; i<n; ++i)
    {
        int mi;
        cin>>mi;
        if (mi<minM)
           minM=mi;
        X-=mi;
        ans++;
    }
    ans+=X/minM;
    cout<<ans<<endl;

    return 0;
}
