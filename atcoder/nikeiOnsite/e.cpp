#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n;

void solve(int x)
{
    int flag=0;
    for (int i=2; i<=6; ++i)
    {
        if (x%i==0)
        {
            printf("%c",'a'+i-2);
            flag+=1;
        }
    }
    if (flag==0) printf("%d",x);
    printf("\n");
}

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        solve(i);

    return 0;
}
