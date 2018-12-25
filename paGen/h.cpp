#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int len[20000];
int num[20000];
int n=0;
char c;
void check(int number,int len)
{
    if (number<=5)
    {
        cout<<number;
        for (int i=0; i<len; ++i)
            cout<<"*2*5";
    }
    else
    {
        cout<<5;
        for (int i=0; i<len; ++i)
            cout<<"*2*5";
        cout<<"+";
        cout<<number-5;
        for (int i=0; i<len; ++i)
            cout<<"*2*5";
    }
}
int main()
{
    int last=-1;
    while (scanf("%c",&c)!=EOF)
    {
        if (c<'0' || c>'9')
            break;
        int t=c-'0';
        num[n]=t;
        if (num[n]) last=n;
        n++;
    }
    for (int i=0; i<n; ++i)
        len[i]=n-i-1;
    for (int i=0; i<n; ++i)
        if (num[i]>0)
        {
            check(num[i],len[i]);
            if (i!=last)
                cout<<"+";
        }
    cout<<endl;
    return 0;
}

