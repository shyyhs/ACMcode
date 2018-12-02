#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int sumN;
ll ans=0;
int w[102][102];
bool p[102];
int wn[102];
int f[105][105];

bool prime(int x)
{
    for (int i=2; i<=sqrt(x); ++i)
        if (x%i==0) return 0;
    return 1;
}

void factor(int x)
{
    int thex=x;
    for (int i=2; i<=x; ++i)
        while (p[i] && (x%i==0))
        {
            w[thex][i]++;
            x/=i;
        }
}
ll factorN(int x)
{
    int ans=1;
    for (int i=2; i<=x; ++i)
        if (w[x][i])
        ans*=(w[x][i]+1);
    return ans;
}

int factorSum(int n)
{
    for (int i=2; i<=n; ++i)
        for (int j=2; j<=n; ++j)
            wn[j]+=w[i][j];
    for (int i=2; i<=n; ++i)
        wn[i]+=1;
/*
    for (int i=2; i<=n; ++i)
        if (wn[i]>0)
        cout<<i<<' '<<wn[i]<<endl;
        */
    return 0;
}

void dp()
{
    memset(f,0,sizeof(f));
    for (int i=1; i<=wn[2]; ++i)
        if (75%i==0)
            f[2][75/i]=i;
        else f[2][75/i]=0;


    for (int i=3; i<=n; ++i)
        for (int j=1; j<=75; ++j)
            if (f[i-1][j])
            {
                for (int k=1; k<=wn[i]; ++k)
                    if (j%k==0)
                        f[i][j/k]+=(f[i-1][j]*k);
            }
    cout<<f[n][1]/75<<endl;
}
void init()
{
    memset(w,0,sizeof(w));
    for (int i=2; i<=100; ++i)
        p[i]=prime(i);
    for (int i=2; i<=100; ++i)
        factor(i);

    /*
    for (int i=2; i<=100; ++i)
    {
        cout<<i<<":";
        for (int j=1; j<=100; ++j)
            if (w[i][j]) cout<<j<<':'<<w[i][j]<<' ';
        cout<<endl;
    }
    */
}

int main()
{
    
    init();
    cin>>n;
    factorSum(n);
    dp();
    return 0;
}


