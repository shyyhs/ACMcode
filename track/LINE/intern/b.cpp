/*
 By shyyhs.
 HP: shyyhs.net
 Github: https://github.com/shyyhs/
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<random>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<tuple>
using namespace std;

#define ll long long
int n;

void init()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        if (i%3==0 && i%5!=0)
            printf("Fizz\n");
        else if (i%5!=0 && i%3==0)
            printf("Buzz\n");
        else if (i%5==0 && i%3==0)
            printf("Fizz Buzz\n");
        else printf("%d\n",i)
    }
}

void work()
{

}

int main()
{
    init();
    work();
    return 0;
}
