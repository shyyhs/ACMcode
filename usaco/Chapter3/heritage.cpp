/*
ID: songskg2
PROG: heritage
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;
char inOrder[100];
char preOrder[100];
int n;
char c;

void dfs(int il,int ir,int pl,int pr)
{
    
    if (il>ir || pl>pr) return;
    for (int i=il; i<=ir; ++i)
        if (inOrder[i]==preOrder[pl])
        {
            dfs(il,i-1,pl+1,pl+(i-il));
            dfs(i+1,ir,pl+(i-il+1),pr);
            cout<<preOrder[pl];
            break;
        }
}

int main()
{
    freopen("heritage.in","r",stdin);
    freopen("heritage.out","w",stdout);
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n')
        {
            break;
        }else
        {
            inOrder[n++]=c;
        }
    }
    for (int i=0; i<n; ++i)
        scanf("%c",&preOrder[i]);
    dfs(0,n-1,0,n-1);
    cout<<endl;



    return 0;
}
