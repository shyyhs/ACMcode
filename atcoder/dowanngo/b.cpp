#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
int a[110000];

void init()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
}
void change(int numLoc,int bitLoc)
{
    for (int j=numLoc+1; j<=n-1; ++j)
        if (a[j]&(1<<bitLoc))
        {
            a[numLoc]^=a[j];



void work()
{
    for (int i=1; i<=n; ++i)
        for (int j=30; j>=0; --j)
            if ((a[i]&(1<<j))==0)
            {
                change(i,j);
            }
}
int main()
{
    init();
    work();
    return 0;
}
