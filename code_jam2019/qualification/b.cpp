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

int test_num;
int n;
char c;
char s[250000];

void work(int case_num)
{
    cin>>n;
    n=(n-1)*2;

    for (int i=1; i<=n; ++i)
    {
        scanf("%c",&c);
        while (c!='E' && c!='S') 
            scanf("%c",&c);
        s[i]=c;
    }
    printf("Case #%d: ",case_num);
    for (int i=1; i<=n; ++i)
    {
        if (s[i]=='S')
            printf("E");
        else printf("S");
    }
    cout<<endl;
}

int main()
{
    cin>>test_num;
    for (int i=1; i<=test_num; ++i)
    {
        work(i);
    }

    return 0;
}

