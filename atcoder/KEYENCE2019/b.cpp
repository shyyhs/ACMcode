#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
char c;
char a[200];
char s[20]={'k','e','y','e','n','c','e','0'};
int len=7;
int n=0;

bool check(int left,int right)
{
    int j=0;
    char st[200];
    int top=0;
    for (int i=0; i<n; ++i)
    {
        if (i>=left && i<=right) continue;
        st[top++]=a[i];
    }
    if (top!=7) return 0;
    for (int i=0; i<top; ++i)
        if (s[i]!=st[i]) return 0;
    return 1;
}


int main()
{
    while (scanf("%c",&c)!=EOF)
    {
        if (c<'a' || c>'z') break;
        a[n++]=c;
    }
    bool flag=0;
    for (int left=0; left<=n; ++left)
        for (int right=left; right<=n; ++right)
        {
            if (check(left,right))
            {
                flag=1;
            }
        }
    if (flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
