/*
ID: songskg2
PROG: gift1
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<cstring>
#include<string>

using namespace std;

FILE *fin=fopen("gift1.in","r");
FILE *fout=fopen("gift1.out","w");

int NP;
char tmp[10000]={0};
char s[15][100000]={0};
map<string,int> mymap;
int money,number;

void init()
{
    fscanf(fin,"%d",&NP);
    for (int i=0; i<NP; ++i)
    {
        fscanf(fin,"%s",&s[i][0]);
        //cout<<s[i]<<endl;
        mymap.insert(pair<string,int>(s[i],0));
        //cout<<tmp<<' '<<mymap[s[i]]<<endl;
    }
}

void work()
{
    while(fscanf(fin,"%s",&tmp[0])!=EOF)
    {
        //cout<<tmp<<endl;
        fscanf(fin,"%d %d",&money,&number);
        money=(number==0)?0:money/number;
        mymap[tmp]-=(money)*number;
        for (int i=0; i<number; ++i)
        {
            fscanf(fin,"%s",&tmp[0]);
            mymap[tmp]+=money;
        }
    }
    for (int i=0; i<NP; ++i)
    {
        fprintf(fout,"%s %d\n",s[i],mymap[s[i]]);
        //cout<<s[i]<<mymap[s[i]]<<endl;
    }
    
}
int main()
{
    init();
    work();
    return 0;
}
