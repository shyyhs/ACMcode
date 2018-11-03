/*
ID: songskg2
PROG: milk
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
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

FILE* fin = fopen("milk.in","r");
FILE* fout = fopen("milk.out","w");
struct M
{
    int cost,amount;
} milk[10000];

int n,m;
char c;
string s;

//fscanf(fin,"",);
//fprintf(fout,"",);

void init()
{
    memset(milk,0,sizeof(milk));
    fscanf(fin,"%d %d",&n,&m);
    for (int i=0; i<m; ++i)
    {
        fscanf(fin,"%d %d",&milk[i].cost,&milk[i].amount);
    }
    sort(milk,milk+m,[](M a,M b){return a.cost<b.cost;});
}

void work()
{
    int sumCost=0;
    for (int shopIndex=0; n; shopIndex++)
    {
        sumCost+=min(n,milk[shopIndex].amount)*milk[shopIndex].cost;
        n-=min(n,milk[shopIndex].amount);
    }
    fprintf(fout,"%d\n",sumCost);

}

int main()
{
    init();
    work();
    return 0;
}
