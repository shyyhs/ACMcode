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
FILE* fin;
FILE* fout;
int n,k;
int a[3000];
char c=' ';


int absent(int i)
{
    int ans=0;
    ans+=(i-1>=1)&a[i-1];
    ans+=a[i];
    ans+=(i+1<=n)&a[i+1];
    return ans;
}

void fillP(int i)
{
    if ((i-1>=1)&&(a[i-1])) a[i-1]=0;
    if (a[i]) a[i]=0;
    if ((i+1<=n)&&a[i+1]) a[i+1]=0;
}

void check(int m)
{
    int absentN=0;
    for (int i=1; i<=n; ++i)
    {
        absentN=absent(i);
        if (absentN==m && k>0)
        {
            fillP(i);
            k--;
        }
    }
}

int tot()
{
    int ans=n;
    for (int i=1; i<=n; ++i)
        ans-=a[i];
    return ans;
}


void work()
{
    for (int i=1; i<=n; ++i)
        cout<<i<<' '<<absent(i)<<endl;

    for (int i=3; i>=0; --i)
        check(i);
    cout<<tot()<<endl;
}

void init()
{
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&k);
    for (int i=1; i<=n; ++i)
    {
        fscanf(fin,"%c",&c);
        while (c!='S' && c!='.') fscanf(fin,"%c",&c);
        a[i]=(c=='S');
    }
}

int main(int argc, char *argv[])
{
    fin = fopen(argv[1],"r");
    init();    
    work();

    return 0;
}
