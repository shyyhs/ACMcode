/*
ID: songskg2
PROG: friday
LANG: C++11
*/

#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
using namespace std;
FILE *fin=fopen("friday.in","r");
FILE *fout = fopen("friday.out","w");

enum Week{Mon=1,Tue,Wed,Tur,Fri,Sat,Sun};
enum Mon{Jan=1,Feb,Mar,Apr,May,June,July,Aug,Sep,Oct,Nov,Dec};

int n;
int week=0;
int sum[10]={0};

void init()
{
    fscanf(fin,"%d",&n);
}

int days_func(int year, int month)
{
    if (month==2) return (year%400==0 || (year%100!=0 && year%4==0))?29:28;
    if (month!=4 && month!=6 && month!=9 && month!=11) return 31; return 30;
}

void work()
{
    for (int year=1900; year<1900+n; ++year)
        for (int month=Jan; month<=Dec; ++month)
            for (int day=1; day<=days_func(year,month); ++day)
                sum[week=(week%7)+1]+=(day==13);
    for (int i=1; i<=7; i++)
        fprintf(fout,"%d%c",sum[(i+4)%7+1],(i==7)?'\n':' ');
}

int main()
{
    init();
    work();
    return 0;
}
