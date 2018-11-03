#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,a[100],sum;
int MIN,MAX,minflag,maxflag;
int main()
{
    n=sum=0;
    memset(a,0,sizeof(a));
    MIN=2000000000;
    MAX=-2000000000;
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
    {
        scanf("%d",&a[i]);
        if (a[i]>MAX) {MAX=a[i];maxflag=i;}
        if (a[i]<MIN) {MIN=a[i];minflag=i;}
    }
    printf("%d\n",2*n);
    if (MAX>=0 && MAX >= -MIN)
    {
        cout<<maxflag+1<<' '<<1<<endl;
        cout<<maxflag+1<<' '<<1<<endl;
        for (int i=0; i<n-1; ++i)
        {
           cout<<i+1<<' '<<i+2<<endl; 
           cout<<i+1<<' '<<i+2<<endl; 
        }
    }else
    {
        cout<<minflag+1<<' '<<n<<endl;
        cout<<minflag+1<<' '<<n<<endl;
        for (int i=n; i>1; --i)
        {
            cout<<i<<' '<<i-1<<endl;
            cout<<i<<' '<<i-1<<endl;
        }
    }
    return 0;
}
                

