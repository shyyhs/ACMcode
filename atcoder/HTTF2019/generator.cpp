#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<random>
using namespace std;
#define minN 1
#define minM 5
#define minL 3
#define maxN 8 
#define maxM 10
#define maxL 8 

FILE *Fout=fopen("r.in","w");
int n,m,l;
int t;
char outC[10]={'S','L','R'};
void init()
{
    srand((unsigned int)time(NULL));
    for (int i=0; i<rand()%10000; ++i) i*i;
    srand((unsigned int)time(NULL));

}
void work()
{
    //n=minN+rand()%(maxN-minN);
    //m=minM+rand()%(maxM-minM);
    n=500;
    m=29;
    l=300;
    //l=minL+rand()%(maxL-minL);
    fprintf(Fout,"%d %d %d\n",n,m,l);
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<l; ++j)
        {
            t=rand()%100;
            if (t<50) t=0;else if (t<75) t=1;else t=2;
            fprintf(Fout,"%c",outC[t]);
        }
        fprintf(Fout,"\n");
    }

}

int main()
{
    init();
    work();
    return 0;
}
