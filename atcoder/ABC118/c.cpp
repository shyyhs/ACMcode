#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
int n;
int a[120000];
int gcdd(int a,int b)
{
    return (a%b==0)?b:gcdd(b,a%b);
}

int main()
{
    cin>>n;
    int ans=0;
    for (int i=0; i<n; ++i)
    {
        scanf("%d",&a[i]);
        ans=(i==0)?a[0]:gcdd(ans,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}

