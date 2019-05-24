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
char c;
char a[1000];
char b[1000];
int t1,t2;

bool check(int pos)
{
    for (int i=0; i<t2; ++i)
    {
        if (a[pos+i]==b[i] || a[pos+i]=='?')
            continue;
        return 0;
    }
    return 1;
}

void print(int pos)
{
    for (int i=0; i<pos; ++i)
        if (a[i]=='?') cout<<'a';
        else cout<<a[i];
    for (int i=0; i<t2; ++i)
        cout<<b[i];
    for (int i=pos+t2; i<t1; ++i)
        if (a[i]=='?') cout<<'a';
        else cout<<a[i];
    cout<<endl;
}


int main()
{
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        a[t1++]=c;
    }
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n' || c==EOF) break;
        b[t2++]=c;
    }
    for (int i=t1-1; i>=0; --i)
        if (check(i))
        {
            print(i);
            return 0;
        }
    cout<<"UNRESTORABLE"<<endl;
    return 0;
}

