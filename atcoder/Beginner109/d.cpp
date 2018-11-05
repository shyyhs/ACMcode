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

int check()
{
    int s=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
        {
            if (w[i][j]%2)
            {
                s++;
                if (s>1) return 1;
            }
        }
    return 0;
}

struct T
{
    int i,j,k,l;
}outS[510*510*20];
int len=0;
void work()
{
    while (check())
    {
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (w[i][j]%2)
                {
                    inFlag=0;
                    for (int k=i; (k<n)&&(!inFlag); ++k)
                        for (int l=(k==i)?j+1:0; (l<m)&&(!inFlag); ++l)
                            if (w[k][l]%2)
                            {
                                inFlag=1;
                                if (i==k||j==l)
                                {
                                    outS[len].i=i; outS[len].j=j; outS[len].k=k; outS[len].l=l; len++;
                                }else
                                    if (w[i][l]%2==0)
                                    {
                                        outS[len].i=i; outS[len].j=j; outS[len].k=i; outS[len].l=l; len++;
                                        outS[len].i=i; outS[len].j=l; outS[len].k=k; outS[len].l=l; len++;
                                    }else
                                        if (w[k][j]%2==0)
                                        {
                                            outS[len].i=i; outS[len].j=j; outS[len].k=k; outS[len].l=j; len++;
                                            outS[len].i=k; outS[len].j=j; outS[len].k=k; outS[len].l=l; len++;
                                        }else
                                        {
                                            outS[len].i=i; outS[len].j=j; outS[len].k=k; outS[len].l=l; len++;
                                        }
                                w[i][j]--; w[k][l]++;
                                i=k; j=l;
                            }
                }
    }   
    cout<<len<<endl;
    for (int i=0; i<len; ++i)
        printf("%d %d %d %d\n",outS[i].i+1,outS[i].j+1,outS[i].k+1,outS[i].l+1);
}


int main()
{
    init();
    work();
    return 0;
}

