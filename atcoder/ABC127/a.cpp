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
    cin >> a>>b;
    if (a>=13)
        cout<<b<<endl;
    if (a>=6 && a<=12)
        cout<<(b/2)<<endl;
    if (a<=5) 
        cout<<0<<endl;
    return 0;
}

