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

struct node
{
    string a;
    int b;
    int index;
};

node t[2000];
int n;

bool cmp(node a, node b)
{
    if (a.a!=b.a) return a.a<b.a;
    return a.b>b.b;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cin>>t[i].a>>t[i].b;
        t[i].index=i;
    }
    sort(t,t+n,cmp);
    for(int i=0; i<n; ++i)
        cout<<t[i].index+1<<endl;
    return 0;
}

