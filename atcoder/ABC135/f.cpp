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

bool all_same(char *s, int l)
{
    for (int i=0; i<l ++i)
        if (s[i]!=s[0]) return 0;
    return 1;
}

bool full_part(char *s1,int l1, char *s2, int l2)
{
}

int main()
{

    s1,s2;
    if (s1[0] == s2[0] && all_same(s1) && all_same(s2))
    {
        cout<<-1<<endl;
        return 0;
    }
    if ((l1>=l2 && full_part(s1,l1,s2,l2)) || (l2>l1 && full_part(s2,l2,s1,l1)))
    {
        cout<<-1<<endl;
        return 0;
    }
    return 0;
}

