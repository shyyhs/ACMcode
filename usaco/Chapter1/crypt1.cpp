/*
ID: songskg2
PROG: crypt1
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

FILE* fin = fopen("crypt1.in","r");
FILE* fout = fopen("crypt1.out","w");

int n;
int tmp[15];
bool flag[10]={0};
int num[10];
int ans=0;
char c;
string s;

//fscanf(fin,"",);
//fprintf(fout,"",);

void init()
{
    fscanf(fin,"%d",&n);
    for (int i=0; i<n; ++i)
    {
        fscanf(fin,"%d",&num[i]);
        flag[num[i]]=1;
        //cout<<num[i]<<endl;
    }
}
bool checkNum(int number)
{
    while (number)
    {
        if (flag[number%10]==0) return 0;
        number/=10;
    }
    return 1;
}
bool check(int tmp[15])
{
    int num1,num2,num3;
    num1=tmp[4]*(tmp[0]*100+tmp[1]*10+tmp[2]);
    num2=tmp[3]*(tmp[0]*100+tmp[1]*10+tmp[2]);
    if (num1>999 || num2>999) return 0;
    num3=num1+num2*10;
    return checkNum(num1)&&checkNum(num2)&&checkNum(num3);
}
void search(int tmp[15],int len)
{
    if (len==5) 
    {
        ans+=check(tmp);
        return;
    }

    for (int i=0; i<n; ++i)
    {
        tmp[len]=num[i];
        search(tmp,len+1);
    }
}
void work()
{
    search(tmp,0);
    //cout<<ans<<endl;
    fprintf(fout,"%d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
