#include<iostream>
using namespace std;
#define ll long long
int n;
ll w[600][600];

ll get(int i,int j)
{
    ll ans=1;
    if (j>0) ans*=w[i][j-1];
    if (j<n-1) ans*=w[i][j+1];
    if (i>0) ans*=w[i-1][j];
    if (i<n-1) ans*=w[i+1][j];
    return ans+1;
}

int main()
{
    cin>>n;
    if (n==2)
    {
        cout<<4<<' '<<7<<endl<<23<<' '<<10<<endl;
        return 0;
    }
    ll left=1;
    ll right = 13000;
    bool f=0;
    for (int i=0; i<n; i++)
        for (int j=i%2; j<n; j+=2)
        {
            if (f==0) w[i][j]=left++;
            else w[i][j]=right--;
            f^=1;
        }
    for (int i=0; i<n; i++)
    {
        for (int j=(i%2)^1; j<n; j+=2)
            w[i][j]=get(i,j);
    }
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            cout<<w[i][j]<<' ';
        if (w[i][j]>1000000000000000)
        {
            cout<<i<<' '<<j<<' '<<"WA"<<endl;
            return 0;
        }
        }
        cout<<endl;
    }
    return 0;
}


