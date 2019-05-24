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

int a,b;

int main()
{
    cin>>a>>b;
    cout<<max(max(2*a-1,2*b-1),a+b)<<endl;
    return 0;
}

