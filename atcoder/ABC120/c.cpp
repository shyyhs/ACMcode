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
int s[100050];
int st[100050];
int t,n;
int ans=0;
char c;

int main()
{
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='\n') break;
        if (c!='0' && c!='1') scanf("%c",&c);
        s[n++]=(c=='1');
    }
    for (int i=0; i<n; ++i)
    {
        st[t++]=s[i];
        while (t>1 && st[t-2]!=st[t-1])
        {
            t-=2;
            ans+=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}

