#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
ll n;
        
int main()
{
    cin>>n;
    n=n%9;
    if (n==1 || n==3 || n==5 || n==7 || n==8)
        cout<<"Win"<<endl;
    else cout<<"Lose"<<endl;
    return 0;
}
