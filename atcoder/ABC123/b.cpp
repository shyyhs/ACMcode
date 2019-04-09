#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;

int a[100];
int k;

bool cmp(int a,int b)
{
    return (a%10)<(b%10);
}
int main()
{
    for (int i=1; i<=5; ++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+5,cmp);
    int flag=1; 
    for (int i=1; i<=5; ++i)
    {
        if (a[i]%10==0)
        {
            k+=a[i];
        }else
        {
            if (flag==0)
            k+=((a[i]/10)+1)*10;
            else
            {
                flag=0;
                k+=a[i];
            }
        }
    }
    cout<<k<<endl;

    return 0;
}

