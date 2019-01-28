#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
int n;
char s[3][1000];
int main()
{
    cin>>n;
    int ans=0;
    for (int k=0; k<3; ++k)
        for (int i=0; i<n; ++i)
            cin>>s[k][i];
    for (int i=0; i<n; ++i)
    {
        if (s[0][i]==s[1][i] && s[1][i]==s[2][i])
        {
            ans+=0;
            continue;
        }
        if (s[0][i]==s[1][i] || s[1][i]==s[2][i] || s[2][i]==s[0][i])
        {
            ans+=1;
            continue;
        }
        ans+=2;
    } 
    cout<<ans<<endl;

    return 0;
}
