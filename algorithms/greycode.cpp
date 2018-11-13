#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int n;

int greycode(int n)
{
    return (n^(n>>1));
}
void print_binary(int num,int width)
{
    while (num<(1<<(width-1)))
    {
        cout<<0;
        width-=1;
    }
    for (;num;num>>=1)
        cout<<(num&1);
    cout<<endl;
}

int main()
{
    cin>>n;
    print_binary(greycode(n),4);
    return 0;
}

