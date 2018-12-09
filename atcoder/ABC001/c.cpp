#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int a,b;
string s[16]={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"}
int main()
{
    cin>>deg>>dis;
    int begin=1125,dif=3375-1125;
    if (deg>=1125 && deg<3375) s = "NNE";
    int num = (deg-1125)/dif;
    if (num>=1 && num<=15)
        cout<<s[num]<<' ';
    else cout<<s[0]<<' ';
    
    return 0;
}


