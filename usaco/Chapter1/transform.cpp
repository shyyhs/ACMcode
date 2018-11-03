/*
ID: songskg2
PROG: transform
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

FILE* fin = fopen("transform.in","r");
FILE* fout = fopen("transform.out","w");

int n,tmp;
char c;
string s;
int wo[15][15];
int wt[15][15];
int wtmp[15][15];
//fscanf(fin,"",);
//fprintf(fout,"",);

bool checkSame(int wo[15][15],int wt[15][15])
{
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (wo[i][j]!=wt[i][j]) return 0;
    return 1;
}

void copyw(int wsource[15][15],int wdest[15][15])
{
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            wdest[i][j]=wsource[i][j];
}

void clockwise90(int w[15][15])
{
    int wtmp[15][15];
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            wtmp[j][n-i-1]=w[i][j];
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            w[i][j]=wtmp[i][j];
}

void reflection(int w[15][15])
{
    int wtmp[15][15];
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            wtmp[i][j]=w[i][n-1-j];
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            w[i][j]=wtmp[i][j];
}

void init()
{
    fscanf(fin,"%d",&n);
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            fscanf(fin,"%c",&c);
            while (c==' ' || c=='\n') fscanf(fin,"%c",&c);
            if (c=='@') wo[i][j]=0; else if (c=='-') wo[i][j]=1; 
            //cout<<wo[i][j]<<' ';
        }
        //cout<<endl;
    }
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            fscanf(fin,"%c",&c);
            while (c==' ' || c=='\n') fscanf(fin,"%c",&c);
            if (c=='@') wt[i][j]=0; else if (c=='-') wt[i][j]=1; 
        }
    }
}

void printw(int w[15][15])
{
    for (int i=0; i<n; ++i,cout<<endl)
        for (int j=0; j<n; ++j)
            cout<<w[i][j]<<' ';
}
int work()
{
   copyw(wo,wtmp);
   clockwise90(wtmp);
    //printw(wtmp);
   if (checkSame(wtmp,wt)) return 1;
   clockwise90(wtmp);
   if (checkSame(wtmp,wt)) return 2;
   clockwise90(wtmp);
   if (checkSame(wtmp,wt)) return 3;
   clockwise90(wtmp);
   reflection(wtmp);
   if (checkSame(wtmp,wt)) return 4;
   for (int i=0; i<3; ++i)
   {
       clockwise90(wtmp);
       if (checkSame(wtmp,wt)) return 5;
   }
   if (checkSame(wo,wt)) return 6;
   return 7;
}

int main()
{
    init();
    fprintf(fout,"%d\n",work());
    return 0;
}
