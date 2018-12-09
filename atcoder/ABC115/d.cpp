#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct T
{
    int l;
    int a[1000];
};
int n;
T k;
char c;
void printT(T x)
{
    for (int i=0; i<x.l; ++i)
        cout<<x.a[i];
    cout<<endl;
}
void reverseT(T &x)
{
    int t;
    for (int i=0; i<x.l/2; ++i)
    {
        t=x.a[i];
        x.a[i]=x.a[x.l-i-1];
        x.a[x.l-i-1]=t;
    }
}

int main()
{
    cin>>n;
    while(1)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        if (c>='0' && c<='9')
            k.a[k.l++]=c-'0';
    }
    reverseT(k);
    printT(k);

    

    return 0;
}
