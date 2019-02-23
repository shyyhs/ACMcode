/*
ID: songskg2
PROG: fracdec
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
int s[200000];
int t;
int flag[1000000];
int n,d,ind;
int main()
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    int lineNum=0;
    cin>>n>>d;
    int ans1=n/d;
    int t1=n%d;
    n=n%d;
    cout<<ans1;
    if (ans1==0) lineNum=1;
    else 
        while (ans1)
        {
            lineNum+=1;
            ans1/=10;
        }

    if (t1==0)
    {
        cout<<".0";
        cout<<endl;
        return 0;
    }
    cout<<'.';
    lineNum+=1;

    for (int i=1; n; i++)
    {
        n*=10;
        int t2=n/d;
        int t3=n%d;
        n=n%d;
        s[t++]=t2;
//        cout<<t2<<endl;
        if (flag[t3])
        {
            if (t3==0)
            {
                ind=-1;
                break;
            }
            ind=flag[t3];
            break;
        }
        flag[t3]=i;
    }
    int flag2=(s[t-1]==s[ind-1]);
    for (int i=0; i<t; ++i)
    {
        if (i==t-1 && ind==-1 && s[i]==0)
            break;
        if (ind>0 && i==t-1 && s[i]==s[ind-1]) break;
        if (ind>0 && (i+1)==ind)
        {
            if (flag2) 
            {
                cout<<'(';
                lineNum+=1;
                if (lineNum==76)
                {
                    cout<<endl;
                    lineNum=0;
                }
            }
        }
        cout<<s[i];
        lineNum+=1;
        if (lineNum==76)
        {
            cout<<endl;
            lineNum=0;
        }
        if (ind>0 && (i+1)==ind)
        {
            if (flag2==0) 
            {
                cout<<'(';
                lineNum+=1;
                if (lineNum==76)
                {
                    cout<<endl;
                    lineNum=0;
                }
            }
        }

    }
    if (ind>0)
    {
        cout<<')';
        lineNum+=1;
        if (lineNum==76)
        {
            cout<<endl;
            lineNum=0;
        }
    }
    if (lineNum!=0)
        cout<<endl;

    return 0;
}
