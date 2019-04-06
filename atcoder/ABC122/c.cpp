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
char c[200000];
int n,q;
int s[200000];
bool flag[200000];
int l,r,ans;


int main()
{
    cin>>n>>q;
    for (int i=1; i<=n; ++i)
    {
        scanf("%c",&c[i]);
        while (!(c[i]>='A' && c[i]<='Z')) scanf("%c",&c[i]);
        s[i]=s[i-1];
        if (c[i]=='C' && c[i-1]=='A')
        {
            flag[i]=1;
            s[i]+=1;
        }
    }
    for (int i=1; i<=q; ++i)
    {
        scanf("%d %d",&l,&r);
        ans = s[r]-s[l-1];
        if (flag[l]) ans--;
        printf("%d\n",ans);
    }
    return 0;
}

