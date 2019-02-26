/*
ID: songskg2
PROG: shopping
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;

ifstream fi("shopping.in");
ofstream fo("shopping.out");
long P[105][6];
long buy[6];
long n,ans;
long c_n[1000];
long F[6][6][6][6][6];
long ori;

void init()
{
    long i,j,m,tp=0,c,k,s,b;
    fi >> s;
    for (i=1;i<=s;i++)
    {
        fi >>m;
        for (j=1;j<=m;j++)
        {
            fi>> c >> k;
            if (c_n[c]==0) c_n[c]=++tp;
            P[i][ c_n[c] ]=k;
        }
        fi >> P[i][0];
    }
    fi >> b;
    for (i=1;i<=b;i++)
    {
        fi>> c >> k >> P[s+i][0];
        if (c_n[c]==0) c_n[c]=++tp;
        P[s+i][ c_n[c] ]=1;
        buy[c_n[c]]=k;
    }
    n=s+b;
    memset(F,0xF,sizeof(F));
    ori=F[0][0][0][0][0];
    F[0][0][0][0][0]=0;
}

void print()
{
    fo << ans <<endl;
    fi.close();
    fo.close();
}

inline long min(long a,long b)
{
    return a<b?a:b;
}

long get(long a1,long a2,long a3,long a4,long a5)
{
    if (F[a1][a2][a3][a4][a5]!=ori)
        return F[a1][a2][a3][a4][a5];
    long i;
    long w1,w2,w3,w4,w5,pmin=ori;
    for (i=1;i<=n;i++)
    {
        w1=a1-P[i][1];w2=a2-P[i][2];w3=a3-P[i][3];w4=a4-P[i][4];w5=a5-P[i][5];
        if (w1<0||w2<0||w3<0||w4<0||w5<0) continue;
        if (F[w1][w2][w3][w4][w5]==ori)
            F[w1][w2][w3][w4][w5]=get(w1,w2,w3,w4,w5);
        pmin=min(pmin,F[w1][w2][w3][w4][w5]+P[i][0]);
    }
    return pmin;
}

int main()
{
    init();
    ans=get(buy[1],buy[2],buy[3],buy[4],buy[5]);
    print();
    return 0;
}
