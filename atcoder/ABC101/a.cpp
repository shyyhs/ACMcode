#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n=0;
char c;

int main()
{
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        if (c=='+') n++;else n--;
    }
    cout<<n<<endl;

    return 0;
}
