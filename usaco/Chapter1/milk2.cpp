/*
ID: songskg2
PROG: milk2
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

FILE *fin=fopen("milk2.in","r");
FILE *fout=fopen("milk2.out","w");
struct T
{
    int startT,endT;
} Time[7000];

int n;

void init()
{
    memset(Time,0,sizeof(Time));
    fscanf(fin,"%d",&n);
    for (int i=0; i<n; ++i)
    {
        fscanf(fin,"%d %d",&Time[i].startT,&Time[i].endT);
        //cout<<Time[i].startT<<' '<<Time[i].endT<<endl;
    }
}

void work()
{
    int start_point,start_index,end_point,end_index;
    int sum1=0,sum2=0;
    int next_index;
    sort(Time,Time+n,[](T a, T b){return a.startT<b.startT;});
    for (start_index=0; end_index=start_index,start_point=Time[start_index].startT,end_point=Time[end_index].endT,end_index<n; ++start_index)
    {
        while (end_index+1<n && Time[end_index+1].startT<=end_point) end_index++,end_point=max(end_point,Time[end_index].endT);
        if (end_index+1<n) next_index=end_index+1;else next_index=-1;
        sum1=max(sum1,end_point-start_point);
        if (next_index>=0) sum2=max(sum2,Time[next_index].startT-end_point);
        //cout<<start_index<<' '<<end_index<<' '<<start_point<<' '<<end_point<<' '<<next_index<<endl;
        start_index=end_index;
    }
        
    //cout<<sum1<<' '<<sum2<<endl;
    fprintf(fout,"%d %d\n",sum1,sum2);
}


int main()
{
    init();
    work();
    return 0;
}


