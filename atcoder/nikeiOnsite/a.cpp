#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char c;

int main()
{
    int n=0;
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='\n') break;
        n++;
        printf("%d\n",n);
    }
    return 0;
}
