#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
ll num[300];
char c;
ll ans=0;
ll odd[300];
int top=0;
ll l=0;

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    while(scanf("%c",&c)!=EOF)
    {
        if (c=='\n') break;
        num[c]++;
    }
    int flag=0;
    for (char c='a'; c<='z'; ++c)
        if (num[c]&1)
        {
            if (flag==0)
            {
                l+=num[c];
                flag=1;
            }else
            {
                l+=num[c]-1;
                ans+=1;
            }
        }
        else
        {
            l+=num[c];
        }
    ans+=l*l;
    cout<<ans<<endl;
    return 0;
}
