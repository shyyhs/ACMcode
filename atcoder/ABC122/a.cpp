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
char c,ans;

int main()
{
    cin>>c;
    if (c=='A') ans='T';
    if (c=='T') ans='A';
    if (c=='C') ans='G';
    if (c=='G') ans='C';
    cout<<ans<<endl;
    return 0;
}

