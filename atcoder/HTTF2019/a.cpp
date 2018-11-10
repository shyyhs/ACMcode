#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<fstream>
#include<ctime>
using namespace std;
FILE* Fin=fopen("r.in","r");
FILE* Fout=fopen("r.out","w");

int n,m,l;
char s[501][400];
int w[30][30];
char outC[10]={'.','#','D','T','L','R'};
int scw[30][30];
int des[30][30];
int ac[501][400];
char c;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int locs[30][30]={0};


void printw()
{
    for (int i=0; i<m; ++i,cout<<endl)
        for (int j=0; j<m; ++j)
            printf("%c",outC[w[i][j]]);
}
void init()
{
    memset(s,0,sizeof(s));
    scanf("%d %d %d",&n,&m,&l);
    for (int i=0; i<n; ++i) scanf("%s",&s[i]);
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
            w[i][j]=(i==0 || i==(m-1) || j==0 || j==(m-1));
}
void printwf()
{
    for (int i=0; i<m; ++i)
    {
        for (int j=0; j<m; ++j) fprintf(Fout,"%c",outC[w[i][j]]);
        fprintf(Fout,"\n");
    }
}
void initf()
{
    memset(s,0,sizeof(s));
    fscanf(Fin,"%d %d %d",&n,&m,&l);
    for (int i=0; i<n; ++i)
        fscanf(Fin,"%s",&s[i]);
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
            w[i][j]=(i==0 || i==(m-1) || j==0 || j==(m-1));
}

void work4(int &x,int &y,int &dir,int ac)
{
    if (ac==0)
    {
        x+=dx[dir]; y+=dy[dir];
        if (w[x][y]==1) x-=dx[dir],y-=dy[dir];
    }
    else if (ac==1)
    {
       dir=(dir==0)?3:dir-1;
    }
    else if (ac==2)
        dir=(dir==3)?0:dir+1;
}
void work3(int &x,int &y,int &dir,int ac)
{
    if (w[x][y]==0) {work4(x,y,dir,ac); return;}
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
    if (w[x][y]==2) {work4(x,y,dir,ac);work4(x,y,dir,ac); return;}
    if (w[x][y]==3) {work4(x,y,dir,ac);work4(x,y,dir,ac);work4(x,y,dir,ac); return;}
}
void trace(int num,int &x,int &y)
{
    int nowx=(m>>1);
    int nowy=(m>>1);
    int dir=0;

    for (int i=0; i<l-1; ++i)
    {
        work3(nowx,nowy,dir,ac[num][i]);
        if (i==299) x=nowx,y=nowy;
    }
}

void work2(int num,int *a)
{
    int nowx=(m>>1);
    int nowy=(m>>1);
    int dir=0;
    for (int i=0; i<l; ++i)
        work3(nowx,nowy,dir,a[i]);
    scw[nowx][nowy]+=1;
}

int scoreAns()
{
    memset(scw,0,sizeof(scw));
    int score=0;
    for (int i=0; i<n; ++i)
        work2(i,ac[i]);
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
        {
            if (scw[i][j]==1) score+=10;else
            if (scw[i][j]==2) score+=3;else
            if (scw[i][j]==3) score+=1;
        }
    return score;
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
void printdes()
{
    for (int i=0; i<m; ++i)
    {
        for (int j=0; j<m; ++j)
            if (scw[i][j]>1)
            cout<<des[i][j]<<' ';else cout<<0<<' ';
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
void workwarp()
{
    int localtmp;
    int addtime=0;
    int tmprun=0;
    int cx,cy,ca,oa;
    int tmpx,tmpy;

    for (int i=0; i<n; ++i)
        for (int j=0; j<l; ++j)
            if (s[i][j]!='S')
                ac[i][j]=s[i][j]=='L'?1:2;

    int preS=scoreAns(),nextS;

    //cout<<"Score of empty map "<<preS<<endl;
    srand((unsigned int)time(NULL));
    for (int i1=1; i1<=27; ++i1)
        for (int j1=1; j1<=27; ++j1)
        {
            int t1=(i1-1)/9,t2=(j1-1)/9;
            if (t1==0 || t1==2) locs[i1][j1]+=5;
            if (t2==0 || t2==2) locs[i1][j1]+=5;
        }
    for (int i=0; i<1980; ++i) 
    {
        cx=1+rand()%(m-2);
        cy=1+rand()%(m-2);
        /*
        while (locs[cx][cy]==0 || (locs[cx][cy]==5 && (i&1)))
        {
            cx=1+rand()%(m-2);
            cy=1+rand()%(m-2);
        }
        */
        //tmprun=rand()%54;
        //if  (tmprun<2) ca=1; else if (tmprun<4) ca=2; else if (tmprun<30) ca=4; else ca=5;
        ca=(i&1)?4:5;        
        if ((cx==14 && cy==14 && ca==1)||(w[cx][cy]==ca))
        {
            i--;
            continue;
        }
        oa=w[cx][cy];
        w[cx][cy]=ca;
        nextS=scoreAns();
        if (nextS>preS )
        {
            addtime++;
            preS=nextS;
        }else
        {
            w[cx][cy]=oa;
        }
    }
    //cout<<"Add time "<<addtime<<endl; cout<<"The final score "<<preS<<endl; 
}

void warp1()
{
    //printwf();
    init();
    workwarp();
    printw();
}
void warpf()
{
    initf();
    workwarp();
    printwf();
    printw();
}

int main()
{
    warp1();
   // warpf();
    return 0;
}

