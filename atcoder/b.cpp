#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int n;
char s;
int flag=0;
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cin>>s;
        if (s=='Y')
            flag=1;
    }
    if (flag) cout<<"Four"<<endl;
    else cout<<"Three"<<endl;
    return 0;
}
