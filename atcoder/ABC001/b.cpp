#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int a,b;

int main()
{
    cin>>a;
    if (a<100) 
    {
        cout<<"00"<<endl;
    }
    if (a>=100 && a<=5000) 
    {
        b=(10*a)/1000;
        if (b<10)
        {
            cout<<0<<int(b)<<endl;
        }else
        {
            cout<<int(b)<<endl;
        }
    }
    if (a>=6000 && a<=30000)
    {
        b=a/1000+50;
        cout<<int(b)<<endl;
    }
    if (a>=35000 && a<=70000)
    {
        b=(a/1000-30)/5+80;
        cout<<int(b)<<endl;
    }
    if (a>70000)
    {
        cout<<89<<endl;
    }
    return 0;
}

