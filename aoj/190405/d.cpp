#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
int t;

int main()
{
    while (true)
    {
        int x,y;
        cin>>x>>y;
        if (x==0 && y==0) break;
        if (x>y)
        {
            t=x;
            x=y;
            y=t;
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}

