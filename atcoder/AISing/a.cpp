#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int n,h,w;
int main()
{
    cin>>n>>h>>w;
    cout<<(n-h+1)*(n-w+1)<<endl;
    return 0;
}
