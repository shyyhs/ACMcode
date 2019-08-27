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
int l,r;

int main()
{
    cin>>n;
    l = n/100;
    r = n%100;
    l = (l>0 && l<=12);
    r = (r>0 && r<=12);
    if (l && r)
        cout<<"AMBIGUOUS"<<endl;
    if (!l && !r)
        cout<<"NA"<<endl;
    if (!l && r)
        cout<<"YYMM"<<endl;
    if (l && !r)
        cout<<"MMYY"<<endl;
    return 0;
}

