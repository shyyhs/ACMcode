#include<iostream>
#define ll long long
using namespace std;
ll a,b,c,k;
int main()
{
    cin>>a>>b>>c>>k;
    k%=2;
    if (k) cout<<b-a<<endl;
    else cout<<a-b<<endl;
    return 0;
}
