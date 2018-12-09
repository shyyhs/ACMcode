#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

int main()
{
    cin>>n;
    if (n==25)
        cout<<"Christmas";
    if (n==24)
        cout<<"Christmas Eve";
    if (n==23)
        cout<<"Christmas Eve Eve";
    if (n==22)
        cout<<"Christmas Eve Eve Eve";
    cout<<endl;

    return 0;
}
