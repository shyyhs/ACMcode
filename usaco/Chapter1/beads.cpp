/*
ID: songskg2
PROG: beads
LANG: C++11
*/

#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;

FILE *fin=fopen("beads.in","r");
FILE *fout=fopen("beads.out","w");

int n;
int beads[400];
bool flag[3]={0};
char c;

void init()
{
    fscanf(fin,"%d",&n);
    for (int i=0; i<n; ++i)
    {
        for (;fscanf(fin,"%c",&c),c=='\n'||c==' ';);
        flag[beads[i]=(c=='b')?0:(c=='w')?2:1]=1;
    }
}
    
int left(int i)
{
    int s=0,color=2;
    for (int j=(i+n-1)%n; color=(color!=2)?color:beads[j],(color==beads[j]||beads[j]==2); j=j+n-1,j%=n) s++;
    return s; 
}
int right(int i)
{
    int s=0,color=2;
    for (int j=i%n; color=(color!=2)?color:beads[j],(color==beads[j]||beads[j]==2); j++,j%=n) s++;
    return s;
}

void work()
{
    if (flag[0]==0 || flag[1]==0){
        fprintf(fout,"%d\n",n);
        return;
    }
    int sum=0;
    for (int i=0; i<n; ++i)
    {
        sum=max(sum,left(i)+right(i));
        //cout<<left(i)<<' '<<right(i)<<endl;
    }
    //cout<<sum<<endl;
    fprintf(fout,"%d\n",min(n,sum));
}

int main()
{
    init();
    work();
    return 0;
}


