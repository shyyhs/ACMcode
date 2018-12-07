#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int ind;
int a;
int ass(int k,int sumlen)
{
    int ans=(sumlen/(k-1));
    if ((sumlen%(k-1))>0) ans++;
    return ans;
}
int main()
{
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
    {
        cin>>a;
        if (a==1) ind=i;
    }
    int ans=2000000;
    for (int i=ind-k+1; i<=ind; ++i)
    {
        int ta=1;
        int start=i;
        if (start<1) continue;
        int e=i+k-1;
        if (e>n) continue;
        ta+=ass(k,start-1-1+1)+ass(k,n-(e+1)+1);
        if (ta<ans) ans=ta;
    }
    cout<<ans<<endl;


    

    return 0;
}
