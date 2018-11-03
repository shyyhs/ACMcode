/*
ID: songskg2
PROG: barn1
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

FILE* fin = fopen("barn1.in","r");
FILE* fout = fopen("barn1.out","w");

int m,s,c;
int tmp;
bool flag[1000]={0};
int startT,endT;
int emptyLen[1000],emptyIndex=0;

//fscanf(fin,"",);
//fprintf(fout,"",);

void init()
{
    startT=3000;
    endT=0;
    fscanf(fin,"%d %d %d",&m,&s,&c);
    for (int i=0; i<c; ++i)
    {
        fscanf(fin,"%d",&tmp);
        startT=min(startT,tmp);
        endT=max(endT,tmp);
        flag[tmp]=1;
    }
}

void work()
{
    for (int blockStart=startT; blockStart<=endT;blockStart++)
    {
        if (flag[blockStart]==1) continue;
        int blockEnd=blockStart;
        while (flag[blockEnd+1]==0)
        {
            blockEnd++;
        }
        emptyLen[emptyIndex++]=blockEnd-blockStart+1;
        //cout<<blockStart<<' '<<blockEnd<<endl;
        blockStart=blockEnd;
    }
    sort(emptyLen,emptyLen+emptyIndex,[](int a,int b){return a>b;});
    int ans=endT-startT+1;
    for (int i=0; i<min(m-1,emptyIndex); ++i)
    {
        ans-=emptyLen[i];
    }
    //cout<<ans<<endl;
    fprintf(fout,"%d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
