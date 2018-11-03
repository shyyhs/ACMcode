#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
int max(int a,int b)
{
    return a>b?a:b;
}
int main(){
    scanf("%d %d",&a,&b);
    printf("%d\n",max(max(a+b,a-b),a*b));
    return 0;
}

