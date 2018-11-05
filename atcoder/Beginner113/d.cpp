#include<iostream>
#define ll long long 
int n,m,k,i,j;
ll d[150][9];
ll p[8]={1,1,2,3,5,8,13,21};
int main()
{
    std::cin>>n>>m>>k;
    d[0][0]=1;
    for (i=0; i<n; ++i)
        for (j=0; j<m;++j)
            d[i+1][j]=(d[i][j]*p[j]*p[m-j-1]+(j>0)*d[i][j-1]*p[j-1]*p[m-j-1]+(j<m-1)*d[i][j+1]*p[j]*p[m-j-2])%1000000007;
    std::cout<<d[n][k-1];
}
