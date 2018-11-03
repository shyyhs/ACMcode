/*
ID: songskg2
PROG: dualpal
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

FILE* fin = fopen("dualpal.in","r");
FILE* fout = fopen("dualpal.out","w");

int n,tmp,s;
char c;

//fscanf(fin,"",);
//fprintf(fout,"",);

void init()
{
    fscanf(fin,"%d %d",&n,&s);
}

bool checkdual(int number, int base)
{
    int tmp[50],len=0;
    while (number)
    {
        tmp[len++]=number%base;
        number/=base;
    }
    for (int i=0; i<len; ++i)
        if (tmp[i]!=tmp[len-1-i]) return 0;
    return 1;
}
void work()
{
    for (int number=s+1;n;number++)
    {
        int total=0;
        for (int base=2; base<=10; ++base)
            if (checkdual(number,base)) total++;
        if (total>=2)
        {
            n--;
            fprintf(fout,"%d\n",number);
        }
    }
}

int main()
{
    init();
    work();
    return 0;
}
