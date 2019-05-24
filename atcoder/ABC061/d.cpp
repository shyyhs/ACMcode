#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define ll long long

#define INF 1000000000000001 
using namespace std;

ll w[1200][1200];
int a,b,n,m;
ll c;


int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (i==j)
                w[i][j]=0;
            else
            {
                w[i][j]=INF;
            }
    for (int i=1; i<=m; ++i)
    {
        cin>>a>>b>>c;
        w[a][b]=-c;
    }
    for(int k = 1;k<=n;k++)
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=n;j++)
                w[i][j] = min(w[i][j],w[i][k]+w[k][j]);

    ll res = -w[1][n];
    for(int i = 1;i<=n;i++){
        if(w[i][i]<0 && w[1][i]<INF&&w[i][n]<INF){
//            res=INF;
            break;
        }
    }
    if (res==INF)
        cout<<"inf"<<endl;
    else cout<<res<<endl;

    return 0;
}
