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
int h[200];
int ans=0;

bool check()
{
    for (int i=0; i<n; ++i)
        if (h[i]>0) return 1;
    return 0;
}
void work()
{
    int i,j;
    for (i=0; i<n; ++i)
        if (h[i])
        {
            ans++;
            h[i]--;
            for (j=i+1; j<n; ++j)
            {
                if (h[j]==0)
                {
                    break;
                }else
                {
                    h[j]--;
                }
            }
            i=j;
        }
}
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>h[i];
    while (check())
    {
        work();
    }
    cout<<ans<<endl;
    return 0;
}
