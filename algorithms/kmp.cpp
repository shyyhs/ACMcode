#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 100010
char s[N*10],st[N*10];
int sL,stL;
int nxt[N];

void getNxt()
{
    int i=0,j=-1;
    nxt[0]=-1;
    while (i<sL)
    {
        if (j==-1||s[j]==s[i]) nxt[++i]=++j;
        else j=nxt[j];
    }
}

int matchS()
{
    int i=0,j=0,count=0;
    while (i<stL)
    {
        if (j==-1 || st[i]==s[j]) i++,j++;
        else j=nxt[j];
        if (j==sL)
        {
            j=nxt[j];
            count++;
        }
    }
    return count;
}


int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s%s",s,st);
        sL=strlen(s);
        stL=strlen(st);
        getNxt();

        for (int i=0; i<sL; ++i)
            cout<<nxt[i]<<' ';
        cout<<endl;

        cout<<matchS()<<endl;
    }
    return 0;
}
