#include<iostream>
#define ll long long
using namespace std;
ll n;
int len=0;
int a[50];
int b[50];

bool check(int loc)
{
    for (int i=loc+1; i<len; ++i)
        if (b[i]!=9)
            return 1;
    return 0;
}


int main()
{
    cin>>n;
    while (n)
    {
        a[len++]=n%10;
        n/=10;
    }
    for (int i=0; i<len; ++i)
    {
        b[i]=a[len-i-1];
    }
    for (int i=0; i<len; ++i)
    {
        if (check(i))
        {
            b[i]=b[i]-1;
            for (int j=i+1; j<len; ++j)
                b[j]=9;
            break;
        }
    }
    int ans=0;
    for (int i=0; i<len; ++i)
    {
        ans+=b[i];
    }
    cout<<ans<<endl;
    
    return 0;
}
