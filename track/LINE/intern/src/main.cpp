/*
 By shyyhs.
 HP: shyyhs.net
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
#include<random>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<tuple>
using namespace std;
#define ll long long
#define maxC 100000*4 //There're Japanese
FILE* fin;
FILE* fout;
int fre[3000]={0};
double frep[300]={0.0};
int sc;
char p[maxC];
int top=0;

char c;

char ansc='e'; 
double maxf=0;

void init()
{
    memset(fre,0,sizeof(fre));
    memset(frep,0,sizeof(frep));
    sc=0;
    maxf=0;
    ansc=0;

    for (int i=0; i<top; ++i)
        if (p[i]>=0)
            fre[p[i]]++;
    for (int i=0; i<256; ++i)
        if ((i>='a' && i<='z') || (i>='A' && i<='Z'))
            sc+=fre[i];
    for (int i=0; i<256; ++i)
        if ((i>='a' && i<='z') || (i>='A' && i<='Z'))
            frep[i]=double(fre[i])/sc;
    for (int i=0; i<256; ++i)
        if (i>='a' && i<='z')
            if (frep[i]>maxf)
            {
                maxf=frep[i];
                ansc=i;
            }
}
void count()
{
    fprintf(fout,"{\n");
    for (int i=0; i<256; ++i)
        if ((i>='a' && i<='z') || (i>='A' && i<='Z') || (i==' '))
        {
            if (i!='z') fprintf(fout,"  \"%c\":%d,\n",char(i),fre[i]);
            else fprintf(fout,"  \"%c\":%d\n",char(i),fre[i]);
        }
    fprintf(fout,"}\n");
}

void space()
{
    fprintf(fout,"{\"char\":\"%c\"}",ansc);
}

void decrypt()
{
    int loc='e';
    int dir=0;
    for (int i=0; i<top; ++i)
    {
        if (p[i]==' ') p[i]=ansc;
        else if (p[i]==ansc) p[i]=' ';
    }

    init();
    dir=ansc-loc;
    for (int i=0; i<top; ++i)
    {
        if (p[i]>='a' && p[i]<='z') 
        {
            p[i]-=dir;
            if (p[i]<'a') p[i]+=26;
            if (p[i]>'z') p[i]-=26;
        } 
        if (p[i]>='A' && p[i]<='Z')
        {
            p[i]-=dir;
            if (p[i]<'A') p[i]+=26;
            if (p[i]>'Z') p[i]-=26;
        }
        fprintf(fout,"%c",p[i]);
    }
}

int main(int argc, char *argv[])
{
    fin = fopen(argv[2],"r");
    fout = fopen(argv[3],"w");
    while (fscanf(fin,"%c",&c)!=EOF) p[top++]=c;
    init();
    if (strncmp(argv[1],"count",10)==0) count();
    if (strncmp(argv[1],"space",10)==0) space();
    if (strncmp(argv[1],"decrypt",10)==0) decrypt();
    return 0;
}
