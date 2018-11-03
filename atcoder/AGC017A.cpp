#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,p;
int a[100];
int f[100][2];
int main(){
    scanf("%d %d",&n,&p);
    for (int i=0; i<n; ++i)
        scanf("%d",&a[i]);
    for (int i=0; i<n; ++i)
        printf("%d\n",a[i]);
    if (a[0]%2==0)
    {
        f[0][0]=1;
        f[0][1]=-1;
    }    
    else{
        f[0][0]=0;
        f[0][1]=0;
    }
    for (int i=1; i<n; ++i)
    {
        if (a[i]%2==0)
        {
            f[i][0]
    return 0;
}
