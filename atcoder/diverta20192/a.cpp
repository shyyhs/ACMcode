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
int n,k;

int main()
{
    cin >> n>>k;
    if (k==1) cout<<0<<endl;
    else cout<<n-k<<endl;
    return 0;
}
