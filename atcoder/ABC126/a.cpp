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
char s[1000];

int main()
{
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
    {
        cin>>s[i];
        if (i==k)
            s[i] = s[i] - ('A' - 'a');
    }
    for (int i=1; i<=n; ++i)
    {
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}

