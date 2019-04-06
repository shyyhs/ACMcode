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
#define ll long long
using namespace std;
int n;
char s;
ll c[300];
ll sf[300][300];
ll ans=0;
ll M=1000000007;


int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        scanf("%c",&s);
        while (s=='\n') scanf("%c",&s);
        c[s]++;
    }
    for (int i=1; i<=26; ++i)
        for (int j='a'; j<='z'; ++j)
        {
            if (i==1)
            {
                sf[i][j]=(sf[i][j-1]+c[j])%M;
            }
            else 
            {
                sf[i][j]=(sf[i][j-1]+sf[i-1][j-1]*c[j])%M;
            }
            ans+=sf[i]['z'];
            ans%=M;
        }
    cout<<ans<<endl;
    return 0;
}

