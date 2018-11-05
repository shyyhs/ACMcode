#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int w[510][510];
int inFlag;
void init()
{
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            scanf("%d",&w[i][j]);
}

struct T
{
    int i,j,k,l;
}ot[500*500*2];
int len=0;
void calNext(int i,int j,int &k,int &l)
{
    if ((i%2==0) && (j<m-1))
    {
        k=i; l=j+1;
    }
    if ((i%2==0) && (j==m-1))
    {
        k=i+1; l=j;
    }
    if ((i%2==1) && (j!=0))
    {
        k=i; l=j-1;
    }
    if ((i%2==1) && (j==0))
    {
        k=i+1; l=j;
    }
}
void work()
{
    for (int i=0; i<n; ++i)
    {
        int Begin=(i%2)?m-1:0;
        int End=(i%2)?-1:m;
        int Itr=(i%2)?-1:1;
        for (int j=Begin; j!=End; j+=Itr)
        {
            if (w[i][j]%2)
            {
                int k,l;
                calNext(i,j,k,l);
                w[i][j]--; w[k][l]++;
                if (k<n){ot[len].i=i; ot[len].j=j;ot[len].k=k;ot[len].l=l;len++;}
            }
        }
    }
    cout<<len<<endl;
    for (int i=0; i<len; ++i)
        printf("%d %d %d %d\n",ot[i].i+1,ot[i].j+1,ot[i].k+1,ot[i].l+1);
}
int main()
{
    init();
    work();
    return 0;
}

