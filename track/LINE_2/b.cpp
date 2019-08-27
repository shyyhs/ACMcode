#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#define ll long long
using namespace std;

ll n,m;
double ans_exp, ans_fac;

void init(char *argv[])
{
    n = stol(argv[1]);
    m = stol(argv[2]);
    ans_exp = n*log(2);
    ans_fac = 0;
    if (m<=30000000)
    {
        for (ll i=1; i<=m; ++i)
            ans_fac += log(i);
    }else
    {
        ans_fac = 0.5*log(2*M_PI*m) + m*(log(m)-1);
    }
    if (ans_exp > ans_fac)
    {
        cout << "Exponential" << endl;
    }else
    {
        cout << "Factorial" << endl;
    }

}


int main(int argc, char*argv[])
{
    init(argv);

    return 0;
}
