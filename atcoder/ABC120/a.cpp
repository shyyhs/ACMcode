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
    cout<<min(c,(b/a))<<endl;
    return 0;
}

