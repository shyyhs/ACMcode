/*
ID: songskg2
PROG: preface
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
int num[4000][8];
int s[8];
char c[8]={'I','I','V','X','L','C','D','M'};
int n;

void calc(int x)
{
    int tx=x;
    int t1=x/1000;
    x%=1000;
    num[tx][7]=t1;
    int t2=x/100;
    x%=100;
    if (t2<=3)
        num[tx][5]=t2;
    else if(t2==4)
    {
        num[tx][5]=1;
        num[tx][6]=1;
    }
    else if (t2==9)
    {
        num[tx][7]+=1;
        num[tx][5]+=1;
    }else
    {
        num[tx][6]=1;
        num[tx][5]=t2-5;
    }
    int t3=x/10;
    x%=10;
    if (t3<=3)
        num[tx][3]=t3;
    else if(t3==4)
    {
        num[tx][3]=1;
        num[tx][4]=1;
    }
    else if (t3==9)
    {
        num[tx][5]+=1;
        num[tx][3]+=1;
    }else
    {
        num[tx][4]=1;
        num[tx][3]=t3-5;
    }
    int t4=x/1;
    x%=1;
    if (t4<=3)
        num[tx][1]=t4;
    else if(t4==4)
    {
        num[tx][1]=1;
        num[tx][2]=1;
    }else if (t4==9)
    {
        num[tx][3]+=1;
        num[tx][1]+=1;
    }else 
    {
        num[tx][2]=1;
        num[tx][1]=t4-5;
    }
}


void addSum(int x)
{
    for (int i=1; i<=7; ++i)
        s[i]+=num[x][i];
}

void print(int x)
{
    for (int i=1; i<=7; ++i)
        cout<<num[x][i]<<' ';
    cout<<endl;
}
int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        calc(i);
        addSum(i);
//        print(i);
    }
    for (int i=1; i<=7; ++i)
        if (s[i])
        {
            cout<<c[i]<<' '<<s[i]<<endl;
        }

    return 0;
}
