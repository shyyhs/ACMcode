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

int tot;
char s[20];
char c;
int b;

int main()
{
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='\n') break;
        if (c=='o') b++;
        tot++;
    }
    if (b+(15-tot)>=8)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

