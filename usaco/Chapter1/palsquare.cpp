/*
ID: songskg2
PROG: palsquare
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

FILE* fin = fopen("palsquare.in","r");
FILE* fout = fopen("palsquare.out","w");

int n,tmp;
char c;
string s;
int ori[15],squ[50];
int oriLen,squLen;
//fscanf(fin,"",);
//fprintf(fout,"",);

void init()
{
    fscanf(fin,"%d",&n);
}
char printC(int num)
{
    if (num<10) return '0'+num;
    return 'A'+(num-10);
}
void printFun(int *arr,int len,bool blFlag)
{
    for (int i=0; i<len; ++i)
    {
        fprintf(fout,"%c",printC(arr[i]));
        //cout<<printC(arr[i]);
    }
    if (blFlag) 
    {
        fprintf(fout,"\n");
        //cout<<endl;
    }else
    {
        //cout<<' ';
        fprintf(fout," ");
    }
}


void change(int num,int *arr,int &len)
{
    int tmp[50];
    len=0;
    while (num)
    {
        tmp[len++]=num%n;
        num/=n;
    }
    for (int j=0; j<len; ++j)
    {
        arr[j]=tmp[len-1-j];
    }
}

bool check(int *arr,int len)
{
    for (int i=0; i<len; ++i)
        if (arr[i]!=arr[len-1-i]) return 0;
    return 1;
}


void work()
{
    for (int i=1; i<=300; ++i)
    {
        change(i,ori,oriLen);
        change(i*i,squ,squLen);
        if (check(squ,squLen))
        {
            printFun(ori,oriLen,0);
            printFun(squ,squLen,1);
        }
    }
}

int main()
{
    init();
    work();
    return 0;
}
