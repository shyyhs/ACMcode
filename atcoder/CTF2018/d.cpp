#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char ch;
char c[100010];

int main()
{
    while (scanf("%c",&ch))
    {
        if (ch>='a' && ch<='z')
            c[n++]=ch;
        if (ch=='\n') break;
    }
    int ans=0;  
    for (int i=0; i<n; ++i)
    {
        int j;
        for (j=i+1; j<n; ++j)
        {
            if (c[i]>=c[j])
                break;
        }
        ans++;
        i=j-1;
    }
    cout<<ans<<endl;
    return 0;
}
