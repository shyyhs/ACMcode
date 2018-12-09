#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m;
char w[150][150];
bool f[150][150];
char c;
int main()
{
    cin>>n>>m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
        {
            scanf("%c",&c);
            while (c=='\n') scanf("%c",&c);
            w[i][j]=c;
        }
    for (int i=0; i<n; ++i)
    {
        bool ff=0;
        for (int j=0; j<m; ++j)
            if (w[i][j]=='#')
                ff=1;
        if (ff==0)
        for (int j=0; j<m; ++j)
            f[i][j]=1;
    }
    for (int j=0; j<m; ++j)
    {
        bool ff=0;
        for (int i=0; i<n; ++i)
            if (w[i][j]=='#')
                ff=1;
        if (ff==0)
            for (int i=0; i<n; ++i)
                f[i][j]=1;
    }
    for (int i=0; i<n; ++i)
    {
        bool ff=0;
        for (int j=0; j<m; ++j)
            if (f[i][j]==0)
            {
                ff=1;
                cout<<w[i][j];
            }
        if (ff)
        cout<<endl;

    }


    
    return 0;
}
