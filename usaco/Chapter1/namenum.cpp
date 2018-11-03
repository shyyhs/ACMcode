/*
ID: songskg2
PROG: namenum
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

FILE* fin = fopen("namenum.in","r");
FILE* fout = fopen("namenum.out","w");
FILE* dic = fopen("dict.txt","r");

int n,tmp;
char c;
char dict[5100][30];
char num[30];
int len;
int dicLines,location;
string s;

//fscanf(fin,"",);
//fprintf(fout,"",);

void init()
{
    dicLines=0,location=0;
    while(fscanf(dic,"%c",&c)!=EOF)
    {
        if (c=='\n')
        {
            dict[dicLines][location]='\0';
            dicLines++;
            location=0;
        }else
        {
            dict[dicLines][location++]=c;
        }
    }
    while(fscanf(fin,"%c",&c)!=EOF && c!='\n')
        num[len++]=c;
}
bool checkPhone(char a, char number)
{
    if (number=='2' && (a=='A' || a=='B' || a=='C')) return 1;
    if (number=='3' && (a=='D' || a=='E' || a=='F')) return 1;
    if (number=='4' && (a=='G' || a=='H' || a=='I')) return 1;
    if (number=='5' && (a=='J' || a=='K' || a=='L')) return 1;
    if (number=='6' && (a=='M' || a=='N' || a=='O')) return 1;
    if (number=='7' && (a=='P' || a=='R' || a=='S')) return 1;
    if (number=='8' && (a=='T' || a=='U' || a=='V')) return 1;
    if (number=='9' && (a=='W' || a=='X' || a=='Y')) return 1;
    return 0;
}
bool check(char *d,char *num)
{
    if (strlen(d)!=strlen(num)) return 0;
    int len=strlen(d);
    for (int loc=0; loc<len; ++loc)
    {
        if (checkPhone(d[loc],num[loc])==0) return 0;
    }
    return 1;
}
void work()
{
    bool printFlag=0;
    for (int dicLine=0; dicLine<dicLines; ++dicLine)
    {
        if (check(dict[dicLine],num))
        {
            printFlag=1;
            //cout<<dict[dicLine]<<endl;
            fprintf(fout,"%s\n",dict[dicLine]);
        }
    }
    if (printFlag==0)
    {
        //cout<<"NONE"<<endl;
        fprintf(fout,"NONE\n");
    }
}

int main()
{
    init();
    work();
    return 0;
}
