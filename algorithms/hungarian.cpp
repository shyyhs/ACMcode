#include<iostream>
using namespace std;
int w[9+10][9+10]; // 1-8 9-17
int wR[9+10][9+10];
int match[20];
int visit[20];
int tag[20];
int independent[20];

void printwR()
{
    for (int i=1; i<=17; ++i)
    {
        for (int j=1; j<=17; ++j)
            cout<<wR[i][j]<<' ';
        cout<<endl;
    }
}
void printw()
{
    for (int i=1; i<=17; ++i)
    {
        for (int j=1; j<=17; ++j)
            cout<<w[i][j]<<' ';
        cout<<endl;
    }
}

void getwR()
{
    for (int i=1; i<=17; ++i)
        for (int j=1; j<=17; ++j)
            if ((i<=8)^(j<=8))
            wR[i][j]=w[i][j]^1;
}

void init()
{
    w[1][1+8]=w[1][2+8]=w[1][7+8]=1;
    w[2][1+8]=w[2][2+8]=w[2][7+8]=w[2][8+8]=1;
    w[3][1+8]=w[3][2+8]=w[3][3+8]=w[3][7+8]=w[3][8+8]=1;
    w[4][1+8]=w[4][3+8]=w[4][7+8]=w[4][8+8]=w[4][9+8]=1;
    w[5][1+8]=w[5][2+8]=w[5][4+8]=w[5][6+8]=1;
    w[6][1+8]=w[6][2+8]=w[6][3+8]=w[6][4+8]=w[6][6+8]=1;
    w[7][1+8]=w[7][3+8]=w[7][4+8]=w[7][5+8]=1;
    w[8][1+8]=w[8][3+8]=w[8][4+8]=w[8][6+8]=1;
    for (int i=1; i<=8; ++i)
        for (int j=9; j<=17; ++j)
            if (w[i][j])
                w[j][i]=1;
}

bool dfs(int u)
{
    for (int i=1; i<=17; ++i)
        if (wR[u][i] && !visit[i])
        {
            visit[i]=1;
            if (match[i]==0 || dfs(match[i]))
            {
                match[i]=u;
                match[u]=i;
                return 1;
            }
        }
    return 0;
}

void hungarian()
{
    int ans=0;
    memset(match,0,sizeof(match));
    for (int i=1; i<=8; ++i)
        if (match[i]==0)
        {
            memset(visit,0,sizeof(visit));
            ans+=dfs(i);
        }
    cout<<17-ans<<endl;
}

void findDfs(int u)
{
    tag[u]=1;
    visit[u]=1;
    if (u<=8)
        if (match[u] && !visit[match[u]]) 
        {
            findDfs(match[u]);
        }
    if (u>=9)
        if (match[u]==0)
            for (int i=1; i<=8; ++i)
                if (wR[u][i] && !visit[i])
                {
                    findDfs(i);
                }
}

void findIndependentPoint()
{
    memset(tag,0,sizeof(tag));
    memset(independent,0,sizeof(independent));
    for (int i=9; i<=17; ++i)
        if (match[i]==0)
        {
            memset(visit,0,sizeof(visit));
            findDfs(i);
        }
    for (int i=1; i<=8; ++i)
        independent[i]=tag[i];
    for (int i=9; i<=17; ++i)
        independent[i]=tag[i]^1;
    cout<<"The maximum clique contains these points:"<<endl;
    cout<<"In the g side:"<<endl;
    for (int i=1; i<=8; ++i)
        if (independent[i]==0)
            cout<<i<<endl;
    cout<<"In the m side:"<<endl;
    for (int i=9; i<=17; ++i)
        if (independent[i]==0)
            cout<<i-8<<endl;
}

int main()
{
    init();
    getwR();
    printwR();
    hungarian();
    cout<<"Match"<<endl;
    for (int i=1; i<=17; ++i)
        cout<<i<<' '<<match[i]<<endl;
    findIndependentPoint();
    return 0;
}
