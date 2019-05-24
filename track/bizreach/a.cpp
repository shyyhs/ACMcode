#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<random>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<tuple>
#define ll long long
using namespace std;

int t;
char s[1000];
char c;

void init(char *argv[])
{
    while (1)
    {
        s[t] = argv[1][t];
        if (s[t]=='\0') break;
        t++;
    }
}

void solve()
{
    for (int i=1; i<t; ++i)
        if (s[i]!='0')
            if (s[0]=='0' || s[i]<s[0])
            {
                c=s[i];
                s[i]=s[0];
                s[0]=c;
            }
    sort(s+1,s+t);
    cout<<s<<endl;
}

int main(int argc, char *argv[])
{
    init(argv);
    solve();
    return 0;
}

