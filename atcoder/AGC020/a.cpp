#include<iostream>
#include<algorithm>
using namespace std;
int a,b,n;

int main()
{
    cin>>n>>a>>b;
    n=max(a-b,b-a);
    if (n%2) cout<<"Borys"<<endl;
    else cout<<"Alice"<<endl;
    
    return 0;
}
