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
int a,b,c;

int main()
{
    cin>>a>>b>>c;
    if (a<b && b<c)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

