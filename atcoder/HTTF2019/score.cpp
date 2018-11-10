#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
using namespace std;
FILE* Fmap=fopen("r.out","r");
FILE* Fin=fopen("r.in","r");
int n,m,l;
char s[20000][400];
int w[40][40];
int scw[40][40];
int ac[20000][400];
char c;
char outC[10]={'.','#','D','T','L','R'};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void init()
{
    fscanf(Fin,"%d %d %d",&n,&m,&l);
    for (int i=0; i<n; ++i)
    {
        fscanf(Fin,"%s",&s[i]);
        for (int j=0; j<l; ++j)
        {
            if (s[i][j]!='S')
                ac[i][j]=s[i][j]=='L'?1:2;
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
        {
            fscanf(Fmap,"%c",&c);
            while (c=='\n' || c==' ') fscanf(Fmap,"%c",&c);
            for (int k=0; k<6; ++k)
                if (c==outC[k])
                    w[i][j]=k;
        }
}
void work4(int &x,int &y,int &dir,int ac)
{
    int newx,newy;
    if (ac==0)
    {
        newx=x+dx[dir];
        newy=y+dy[dir];
        if (w[newx][newy]!=1)
        {
            x=newx;
            y=newy;
        }
        return;
    }
    if (ac==1)
    {
       dir=(dir+3)%4;
       return;
    }
    if (ac==2)
    {
        dir=(dir+1)%4;
    }
}
void work3(int &x,int &y,int &dir,int ac)
{
    if (w[x][y]==0) {work4(x,y,dir,ac); return;}
    if (w[x][y]==2) {for (int i=0; i<2; ++i) work4(x,y,dir,ac); return;}
    if (w[x][y]==3) {for (int i=0; i<3; ++i) work4(x,y,dir,ac); return;}
    if (w[x][y]==4) 
    {
        if (ac==2) ac=1;
        work4(x,y,dir,ac);
        return;
    }
    if (w[x][y]==5)
    {
        if (ac==1) ac=2;
        work4(x,y,dir,ac);
        return;
    }
}

void work2(int *a)
{
    int nowx=(m)/2;
    int nowy=(m)/2;
    int dir=0;
    for (int i=0; i<l; ++i)
    {
        /*
        int tmp[40][40]={0};
        tmp[nowx][nowy]=dir+1;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                cout<<tmp[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<nowx<<' '<<nowy<<' '<<w[nowx][nowy]<<' '<<dir<<' '<<a[i]<<endl;
        */
        work3(nowx,nowy,dir,a[i]);    
    }
    scw[nowx][nowy]+=1;
}

void printmap()
{
    for (int i=0; i<m; ++i)
    {
        for (int j=0; j<m; ++j)
            cout<<scw[i][j];
        cout<<endl;
    }
    cout<<endl;
}

void calcu()
{
#define z 9
    int cal[z][z]={0};
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
            cal[(i-1)/(27/z)][(j-1)/(27/z)]+=scw[i][j];
    for (int i=0; i<z; ++i)
    {
        for (int j=0; j<z; ++j)
            cout<<cal[i][j]<<' ';
        cout<<endl;
    }
}

void work()
{
    int score=0;
    for (int i=0; i<n; ++i)
    {
        work2(ac[i]);
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
        {
            if (scw[i][j]==1) score+=10;else
            if (scw[i][j]==2) score+=3;else
            if (scw[i][j]==3) score+=1;
        }
    calcu();
    printmap();
    cout<<score<<endl;
}

int main()
{
    init();
    work();
    return 0;
}
