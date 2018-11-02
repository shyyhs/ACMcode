/*
ID: songskg2
PROG: ride
LANG: C++11
*/

#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
using namespace std;

FILE *fin = fopen("ride.in","r");
FILE *fout = fopen("ride.out","w");

char s[2][10];

void init()
{
    for (int i=0; i<2; ++i)
    {
        fscanf(fin,"%s",&s[i][0]);
        //cout<<s[i]<<endl;
        //cout<<strlen(s[i])<<endl;
    }
}
void work()
{
    int sum[2]={1,1};
    for (int j=0; j<2; ++j)
        for (int i=0; i<strlen(s[j]); ++i)
        {
            //cout<<s[j][i]<<' '<<int(s[j][i])<<endl;
            sum[j]*=int(s[j][i])-int('A')+1;
        }
    //cout<<sum[0]<<' '<<sum[1]<<endl;
    if (sum[0]%47==sum[1]%47)
        fprintf(fout,"GO");
    else fprintf(fout,"STAY");
    fprintf(fout,"\n");
}

int main()
{
    init();
    work();    
    return 0;
}
