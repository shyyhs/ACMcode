#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
char c[15];
int top=0;
int num;
int minN=10000;
int getnum(char c1,char c2,char c3)
{
    return 100*(c1-'0')+10*(c2-'0')+(c3-'0');
}

int abs(int a)
{
    if (a<0) return -a;
    return a;
}

int main()
{
    while (true)
    {
        scanf("%c",&c[top]);
        if (c[top]==EOF || c[top]=='\n' || c[top]==' ') break;
        top++;
    }
    for (int i=0; i<=top-3; ++i)
    {
        num=getnum(c[i],c[i+1],c[i+2]);
        num = abs(num-753);
        if (num<minN)
            minN=num;
    }
    cout<<minN<<endl;

    return 0;
}


