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
int n;
int a1,a2;

int main()
{
    cin>>n;
    char c;
    for (int i=1; i<=n; ++i)
    {
        scanf("%c",&c);
        if (c!='R' && c!='B')
            scanf("%c",&c);
        if (c=='R') a1++;
        else a2++;
    }
    if (a1>a2)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

