#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<random>
using namespace std;

int n;
void init()
{
    scanf("%d",&n);
}

void work()
{
    int a,b;
    if (n==1)
    {
        printf("Hello World\n");
    }else
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b);
    }
}


int main()
{
    init();
    work();

    return 0;
}

