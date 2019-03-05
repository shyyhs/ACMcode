#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int n;
int flag[300000];
int s[300000];
int l,r;

int main()
{
    for (int i=2; i<=200000; ++i)
        flag[i]=1;
    for (int i=2; i<=200000; ++i)
    {
        for (int j=i*2; j<=200000; j+=i)
         flag[j]=0;
    }
    for (int i=2; i<=200000; ++i)
        s[i]=s[i-1]+(flag[i] && flag[(i+1)>>1]);
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}
