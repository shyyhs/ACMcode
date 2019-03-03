#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[200000];

int main()
{
    scanf("%d",&n);
    int maxNum=0;
    int idx1=0;
    int idx2=0;
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        if (a[i]>maxNum)
        {
            maxNum=a[i];
            idx1=i;
        }
    }
    int maxDiff=0;
    for (int i=1; i<=n; ++i)
        if (min(a[i],maxNum-a[i])>maxDiff)
        {
            maxDiff=min(a[i],maxNum-a[i]);
            idx2=i;
        }
    cout<<a[idx1]<<' '<<a[idx2]<<endl;
    return 0;
}
