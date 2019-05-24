/*
 By shyyhs
Github: https://github.com/shyyhs/
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#define ll long long
using namespace std;
ll a,b,m;

ll gcd(ll a, ll b)
{
    return (b)?gcd(b,a%b):a;
}

ll change(char *s)
{
    int i=0;
    ll ans=0;
    while (true)
    {
        if (s[i]<'0' || s[i]>'9') break;
        ans=ans*10+s[i]-'0';
        i++;
    }
    return ans;

}

bool check(ll x)
{
    if (x<2) return 0;
    for (int i=2; i<=sqrt(x)+1; ++i)
        if ((x%i)==0) return 0;
    return 1;
}

void work()
{
    for (int n=1; 1; n++)
    {
        if (check(n*a+b)) 
        {
            m--;
        }
        if (m==0)
        {
            cout<<n*a+b<<endl;
            return;
        }
    }
}

void init()
{
    cout<<a<<' '<<b<<' '<<m<<endl;

}

bool errCheck(char *s)
{
    int i=0;
    while (1)
    {
        char c=s[i];
        if ((c<'0' || c>'9') && (c!='\0')) return 1;
        if (c=='\0') return 0;
        i++;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    
    if (argc!=4 || errCheck(argv[1]) || errCheck(argv[2]) || errCheck(argv[3]))
    {
        cout<<-1<<endl;
        return 0;
    }
    a = change(argv[1]);
    b = change(argv[2]);
    m = stoi(argv[3]);
    if (gcd(a,b)>1)
    {
        cout<<-1<<endl;
        return 0;
    }
    work();

    return 0;
}
