/*
ID: songskg2
PROG: comehome
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;
int n,m,z;
char x,y;
int w[125][125][125];
int d[125][125];

bool check(int x)
{
    return ((x>='a' && x<='z') || (x>='A' && x<='Z'));
}

int main()
{
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    cin>>m;
    for (int i=0; i<125; ++i)
        if (check(i))
        for (int j=0; j<125; ++j)
            if (check(j))
                d[i][j]=1000000;

    for (int i=1; i<=m; ++i)
    {
        cin>>x>>y>>z;
        if (d[x][y]>z)
        {
            d[x][y]=d[y][x]=z;
        }
    }
    for (int k=0; k<125; ++k)
        if (check(k))
            for (int i=0; i<125; ++i)
                if (check(i))
                    for (int j=0; j<125; ++j)
                        if (check(j))
                            if (i!=j && j!=k)
                                if (d[i][k]+d[k][j]<d[i][j])
                                    d[i][j]=d[i][k]+d[k][j];
    int ans=1250000;
    char ind;
    for (int i='A'; i<='Y'; ++i)
        if (d[i]['Z']<ans)
        {
            ind=i;
            ans=d[i]['Z'];
        }
    cout<<ind<<' '<<ans<<endl;


    return 0;
}
