#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

void init()
{
cin>>n;
}

void work()
{
for (int i=n;;i++)
{
    int j=i;

    int a=j/100;
    j-=a*100;
    int b=j/10;
    j-=b*10;
    int c=j;
    if (a==b && b==c)
    {
        cout<<i<<endl;
        return;
    }
    
} 
}


int main()
{
    init();
    work();
    return 0;
}

