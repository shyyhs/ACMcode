#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
int n;
int a[300000];
int MAXN = 2147483647;

void init()
{
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
        scanf("%d",&a[i]);
}

bool check(int ind)
{
    if (ind<1) return 0;
    if (ind>=2147483647) return 1;
    return 0;
}

int binarySearch(int l,int r)
{
    int mid=0;
    while (l<=r)
    {
        mid=l+(r-l)/2;
        bool checkMid=check(mid);
        bool checkPre=check(mid-1);
        if (checkMid==1 && checkPre==0)
            return mid;
        if (checkMid)
            r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main()
{
    init();
    cout<<binarySearch(1,MAXN)<<endl;
    return 0;
}
