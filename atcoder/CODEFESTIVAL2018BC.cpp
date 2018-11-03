#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

int n;
int w[1010][1010];
int main()
{
    scanf("%d",&n);
    memset(w,0,sizeof(w));
    for (int i=0; i<n; ++i)
    {
        for (int j=(i*2)%5; j<n; j+=5)
            w[i][j]=1;
        if (i==0 || i==n-1)
            for (int j=(i*2+3)%5; j<n; j+=5)
                w[i][j]=1;
        if (w[i][0]==0 && w[i][1]==1) w[i][1]=1;
        if (n>1&&w[i][n-1]==0 && w[i][n-2]==0) w[i][n-2]=1;
    }
    for (int i=0; i<n; ++i,cout<<endl)
        for (int j=0; j<n; ++j)
            printf("%c",(w[i][j]==0)?'.':'X');
    return 0;
}
