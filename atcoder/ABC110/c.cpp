#include<iostream>
#include<cstdio>
#include<algorithm>
#define M 100000007
using namespace std;
char c;
int a1[30];
int a2[30];
int n=0;

int main()
{
    for (int i=0; i<26; ++i)
        a1[i]=a2[i]=1;
    while (true)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        a1[c-'a']*=(++n);
        if (a1[c-'a']>10000000) a1[c-'a']%=M;
    }
    for (int i=1; i<=n; ++i)
    {
        scanf("%c",&c);
        a2[c-'a']*=(i);
        if (a2[c-'a']>10000000) a2[c-'a']%=M;
    }
    sort(a1,a1+26);
    sort(a2,a2+26);
    bool flag=1;
    for (int i=0; i<='z'-'a'; ++i)
        if (a1[i]!=a2[i])
            flag=0;
    if (flag==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

