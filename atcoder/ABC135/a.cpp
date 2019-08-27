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
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;
ll a,b;

int main()
{
         cin >> a>>b;
     if ((a+b)%2 ==1)
         cout<<"IMPOSSIBLE"<<endl;
    else
         cout<<(a+b)/2<<endl;
    return 0;
}

