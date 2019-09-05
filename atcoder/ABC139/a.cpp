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
char s[3];
char t[3];
char c;
int ans = 0;


int main()
{
    for (int i=0; i<3; ++i)
    {
        scanf("%c",&c);
        while (c=='\n') scanf("%c",&c);
        s[i] = c;
    }
    for (int i=0; i<3; ++i)
    {
        scanf("%c",&c);
        while (c=='\n') scanf("%c",&c);
        t[i] = c;
    }
    for (int i=0; i<3; ++i)
    {
        ans += (s[i] == t[i]);
    }
    cout << ans << endl;
    return 0;
}

