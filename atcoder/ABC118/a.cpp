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

int a,b;
int main()
{
    cin>>a>>b;
    if (b%a==0) cout<<a+b; else cout<<b-a;
    cout<<endl;
    return 0;
}

