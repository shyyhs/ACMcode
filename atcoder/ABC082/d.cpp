#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int x,y;
int s[2][50000];
int flag[2][50000];
int t[2];

char c;
bool cmp(int a,int b)
{
    return b>a;
}
int main()
{
    int now=0;
    int num=0;
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        if (c=='T')
        {
            s[now][t[now]++]=num;
            num=0;
            now^=1;
        }
        else
        {
            num++;
        }
    }
    s[now][t[now]++]=num;
    cin>>x>>y;
    sort(s[0]+1,s[0]+t[0],cmp);
    sort(s[1],s[1]+t[1],cmp);

    int nowx=s[0][0];
    for (int i=1; i<t[0]; ++i)
        if (nowx<x) nowx+=s[0][i];
        else nowx-=s[0][i];
    int nowy=0;
    for (int i=0; i<t[1]; ++i)
        if (nowy<y) nowy+=s[1][i];
        else nowy-=s[1][i];
    if (nowx==x && nowy==y)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
