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
char c;
int t;
int ans;
int now;

bool check(char c)
{
    if (c=='A' || c=='C' || c=='G' || c=='T')
        return 1;
    return 0;
}

int main()
{
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='\n') break;
        if (!(c>='A' && c<='Z')) continue;
        if (check(c))
        {
            now+=1;
        }else
        {
            now=0;
        }
        if (now>ans)
            ans=now;
    }
    cout<<ans<<endl;
    return 0;
}

