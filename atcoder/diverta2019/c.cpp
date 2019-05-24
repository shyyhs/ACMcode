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
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;

int n;
int ans=0;

int l[20000],r[20000];
int len[20000];
char c;
char s[11000][15];

void init()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        len[i]=0;
        while (1)
        {
            scanf("%c",&c);
            if (c=='\n')
            {
                if (len[i]==0) continue;
                else break;
            }
            s[i][len[i]]=c;
            len[i]++;
        }
    }
    for (int i=1; i<=n; ++i)
    {
        if (s[i][0] == 'A') l[i]=1;
        if (s[i][0] == 'B') l[i]=2;
        if (s[i][len[i]-1] == 'A') r[i]=1;
        if (s[i][len[i]-1] == 'B') r[i]=2;
    }
}

void solve()
{
    for (int i=1; i<=n; ++i)
        for (int j=0; j<len[i]-1-1; ++j)
            if (s[i][j]=='A' && s[i][j+1]=='B')
                ans++;
    int rA = 0, lB =0, rAlB=0;
    for (int i=1; i<=n; ++i)
    {
        if (r[i]==1 && l[i]==2) rAlB++;
        else if (r[i]==1) rA++;
        else if (l[i]==2) lB++;
    }
    if (rAlB==0)
    {
        ans+=min(rA,lB);
    }else
    {
        ans+=rAlB-1;
        if (rA>0)
        {
            rA--;
            ans++;
        }
        if (lB>0)
        {
            lB--;
            ans++;
        }
        ans+=min(rA,lB);
    }
    cout<<ans<<endl;
}

int main()
{
    init();
    solve();
    return 0;
}

