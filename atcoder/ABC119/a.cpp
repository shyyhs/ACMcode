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
char c;

int main()
{
    int flag=1;
    cin>>n;
    cin>>c;
    if (n<2019) flag=0;
    cin>>n;
    cin>>c;
    if (n<5) flag=0;
    cin>>n;
    if (flag==0)
        cout<<"Heisei"<<endl;
    else cout<<"TBD"<<endl;
    return 0;
}

