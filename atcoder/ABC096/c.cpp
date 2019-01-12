#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int w[60][60];
int tw[60][60];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            char c;
            scanf("%c",&c);
            while (c!='.' && c!='#') scanf("%c",&c);
            if (c=='.') w[i][j]=0; else w[i][j]=1;
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (w[i][j])
               for (int k=0; k<4; ++k)
                {
                    int nx,ny;
                    nx = i+dx[k];
                    ny = j+dy[k];
                    if (w[nx][ny])
                    {
                        tw[nx][ny]=1;
                        tw[i][j]=1;
                    }
                }
    bool flag=1;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (tw[i][j]!=w[i][j])
                flag=0;
    if (flag==1) cout<<"Yes"<<endl;else cout<<"No"<<endl;


    return 0;
}
