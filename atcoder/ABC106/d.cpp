#include<iostream>
using namespace std;
int n,m,q;
int a[510][510];
int s[510][510];
int l,r;

int main()
{
    cin>>n>>m>>q;
    for (int i=0; i<m; ++i)
    {
        cin>>l>>r;
        a[l][r]+=1;
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            s[i][j]=s[i][j-1]+a[i][j];
    for (int i=1; i<=q; ++i)
    {
        cin>>l>>r;
        int ans=0;
        for (int j=l; j<=r; ++j)
            ans+=s[j][r];
        cout<<ans<<endl;
    }
    return 0;
}
