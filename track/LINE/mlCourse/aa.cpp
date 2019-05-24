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
int suma[3000];
char c=' ';
int f[2002][2002][2];
bool flag[2002][2002][2];

int dp(int i,int j,int s)
{
    if (flag[i][j][s]) return f[i][j][s];
    if (i<=0) return 0;
    if (j==0)
    {
        if (s==0) return suma[i];
        if (s==1)
        {
            if (i<=2) return i;
            return suma[i-2]+2;
        }
    }

    flag[i][j][s]=1;

    int ans=0;
    if (i>1)
        ans=dp(i-1,j-1,1)+1;
    else ans=0;

    if (s==1)
    {
        int inc=2;
        if (i==1) inc=1;
        ans=max(ans,dp(i-2,j,0)+inc);
        ans=max(ans,dp(i-2,j-1,1)+inc);
    }
    if (s==0)
    {
        if (i>1)
            ans=max(ans,dp(i-1,j-1,1)+1);
        ans=max(ans,dp(i-1,j,0)+(1-a[i]));
    }

    f[i][j][s]=ans;
    return ans;
}


void work()
{
    cout<<max(dp(n,k,0),dp(n,k-1,1))<<endl;
}

void init()
{
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&k);
    suma[0]=0;
    for (int i=1; i<=n; ++i)
    {
        fscanf(fin,"%c",&c);
        while (c!='S' && c!='.') fscanf(fin,"%c",&c);
        a[i]=(c=='S');
        suma[i]=suma[i-1]+(1-a[i]);
    }
}

int main(int argc, char *argv[])
{
    fin = fopen(argv[1],"r");
    init();    
    work();

    return 0;
}
