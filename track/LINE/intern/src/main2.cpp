/*
 By shyyhs.
 HP: shyyhs.net
 Github: https://github.com/shyyhs/
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<random>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<tuple>
using namespace std;
#define ll long long

int m;
struct T
{
    int num;
    string ss;
} tmp[100];
int top=0;

bool P(int x)
{
    if (x<=1) return 0;
    for (int i=2; i<=sqrt(x); ++i)
        if (x%i==0)
            return 0;
    return 1;
}

bool cmp(T a, T b)
{
    return a.num<b.num;
}

int main(int argc, char *argv[])
{
    m = stoi(argv[argc-1]);
    bool oflag =0; 
    for (int i = 1; i < argc-1; i++) 
    { 
        char num[200]={0};
        char ss[200]={0};
        int strBegin =0;
        for (int j=0; j<1000; ++j)
            if (argv[i][j]!=':')
                num[j]=argv[i][j];
            else
            {
                num[j+1]='\0';
                strBegin=j+1;
                break;
            }
        for (int j=strBegin; j<1000; ++j)
            if (argv[i][j]!='\0')
                ss[j-strBegin]=argv[i][j];
            else
            {
                ss[j-strBegin]=argv[i][j];
                break;
            }
        tmp[i-1].num=stoi(num);
        tmp[i-1].ss=ss;
    }
    top = (argc-2);
    sort(tmp,tmp+top,cmp);
    for (int i=0; i<top; ++i)
        if (m%tmp[i].num==0)
        {
           oflag=1;
           cout<<tmp[i].ss;
        } 
    if (!oflag)
    {
        if (P(m)) cout<<"prime"<<endl;
        else cout<<m<<endl;
    }
    return 0;
}
