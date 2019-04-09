#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<ctime>
#include<algorithm>
#define ll long long 
using namespace std;
int n;
char c;
int t;
int a[60000];
int b[60000];

void work(int num)
{
    t = 0;
    while (1)
    {
        if (scanf("%c",&c)==EOF) break;
        if (c=='\n') break;
        t++;
        a[t]=c-'0';
        b[t]=0;
        if (a[t]==4)
        {
            a[t]=3;
            b[t]=1;
        }
    }
    cout<<"Case #"<<num<<": ";
    for (int i=1; i<=t; ++i)
        printf("%d",a[i]);
    cout<<' ';
    bool flag=0;
    for (int i=1; i<=t; ++i)
    {
        if (b[i]==0 && flag==0) continue;
        flag=1;
        printf("%d",b[i]);
    }
    cout<<endl;
}

int main()
{
    cin>>n;
    scanf("%c",&c);

    for (int i=1; i<=n; ++i)
        work(i);
    return 0;
}

