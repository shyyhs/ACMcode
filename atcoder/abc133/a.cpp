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

int n,a,b;

int main()
{
    cin >> n>> a>>b;
    cout<<min(n*a,b)<<endl;

    return 0;
}

