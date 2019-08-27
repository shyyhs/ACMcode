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
int n;
int a[100];

bool check()
{
    for (int i=0; i<n-1; ++i)
        if (a[i]>a[i+1]) return 0;
    return 1;
}

int main()
{
    int flag=0;
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    if (check()) flag=1;
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
        {
            swap(a[i],a[j]);
            if (check()) flag=1;
            swap(a[i],a[j]);
        }
    if (flag==0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}

