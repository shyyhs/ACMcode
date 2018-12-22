#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<ctime>
#include<random>
#include<map>
#define ll long long
using namespace std;
char c;
int n;
ll sumLoc=0;
ll sumB=0;

int main()
{
    int loc=0;
    while (true)
    {
        scanf("%c",&c);
        if (c!='B' && c!='W') break;
        n++;
        loc=n-1;
        if (c=='B')
        {
            sumLoc+=loc;
            sumB+=1;
        }
    }
    ll startLoc = loc-sumB+1;
    ll finalLoc = loc;
    cout<<(finalLoc+startLoc)*sumB/2-sumLoc<<endl;
    return 0;
}


