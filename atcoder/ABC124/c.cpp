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
char s[200000];
char c;
int t=0;

int main()
{
    while (1)
    {
        scanf("%c",&c);
        if (c!='0' && c!='1') break;
        s[t++]=c;
    }
    int ans1=0;
    int ans2=0;
    for (int i=0; i<t; ++i)
    {
        ans1+=(s[i]==((i%2)+'0'));
        ans2+=(s[i]==((i+1)%2+'0'));
    }
    cout<<min(ans1,ans2)<<endl;

    return 0;
}

