/*
ID: songskg2
PROG: spin
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
int s[6];
bool flag[6][361];
bool tflag[6][361];
int gcd(int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
bool check()
{
    for (int i=0; i<=359; ++i)
    {
        bool f=1;
        for (int j=1; j<=5; ++j)
            if (flag[j][i]==0)
                f=0;
        if (f==1) return 1;
    }
    return 0;
}
void change()
{
    memset(tflag,0,sizeof(tflag));
    for (int i=1; i<=5; ++i)
        for (int j=0; j<=359; ++j)
            if (flag[i][j])
                tflag[i][(j+s[i])%360]=1;
    for (int i=1; i<=5; ++i)
        for (int j=0; j<=359; ++j)
            flag[i][j]=tflag[i][j];
}

int main()
{
    freopen("spin.in","r",stdin);
    freopen("spin.out","w",stdout);
    for (int i=1; i<=5; ++i)
    {
        cin>>s[i];
        int m;
        cin>>m;
        for (int j=1; j<=m; ++j)
        {
            int startP,span;
            cin>>startP>>span;
            for (int k=0; k<=span; ++k)
            {
                int now=(startP+k)%360;
                flag[i][now]=1;
            }
        }
    }
    int lmt=s[1];
    for (int i=2; i<=5; ++i)
        lmt=lmt*s[i]/gcd(lmt,s[i]);
    for (int i=0; i<=50000; ++i)
    {
        if (check())
        {
            cout<<i<<endl;
            return 0;
        }
        change();
    }
    cout<<"none"<<endl;
    return 0;
}
