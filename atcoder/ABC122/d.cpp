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
#define M 1000000007
using namespace std;
int n;
ll ans=0;
int num[300];
char c[4]={'A','C','G','T'};
ll f[200][400];
bool flag[200][400];

ll h(string S)
{
    int ans=0;
    for (int i=0; i<3; ++i)
    {
        ans=ans*4+num[S[i]];
    }
    return ans;
}

bool check3(string s)
{
    if (s=="AGC") return 0;
    return 1;
}

bool check2(string s)
{
    for (int i=0; i<=1; ++i)
    {
        if (check3(s.substr(i,3))==0) return 0;
    }
    return 1;
}

bool check(string s)
{
    for (int i=0; i<3; ++i)
    {
        if (check2(s)==0) return 0;
        char t=s[i];
        s[i]=s[i+1];
        s[i+1]=t;
        if (check2(s)==0) return 0;
        t=s[i];
        s[i]=s[i+1];
        s[i+1]=t;
    }

    return 1;
}

ll dp(int n,string S)
{
    if (n<=3)
    {
        if (S=="AGC" || S=="ACG" || S=="GAC") return 0;
        return 1;
    }
    if (flag[n][h(S)]==1)
        return f[n][h(S)];
    flag[n][h(S)]=1;
    f[n][h(S)]=0;

    for (int i=0; i<4; ++i)
    {
        if (check(c[i]+S))
        {
            f[n][h(S)]+=dp(n-1,c[i]+S.substr(0,2));
            f[n][h(S)]%=M;
        }
    }

    return f[n][h(S)];
}


void dfs(int now,string S)
{
    if (now==3)
    {
        //cout<<n<<' '<<S<<' '<<dp(n,S)<<endl;
        ans+=dp(n,S);
        ans%=M;
    }else
    {
        for (int i=0; i<4; ++i)
        {
            dfs(now+1,S+c[i]);
        }
    }
}
        


int main()
{
    num['A']=0;
    num['C']=1;
    num['G']=2;
    num['T']=3;
    cin>>n;

    dfs(0,"");

    cout<<ans<<endl;
    return 0;
}

