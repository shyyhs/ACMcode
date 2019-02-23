#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
int w[9+10][9+10]; // 1-8 9-17
set <int> P,R,X,n[19];

void printw()
{
    for (int i=1; i<=17; ++i)
    {
        for (int j=1; j<=17; ++j)
            cout<<w[i][j]<<' ';
        cout<<endl;
    }
}

void printSet(set <int> S)
{
    for (set<int>::iterator itr=S.begin(); itr!=S.end(); ++itr)
        cout<<*itr<<' ';
    cout<<endl;
}

void printClique(set <int>S)
{
    static int num=0;
    bool flag1=0,flag2=0;
    for (set<int>::iterator itr=S.begin(); itr!=S.end(); ++itr)
        flag1+=(*itr<=8),flag2+=(*itr>8);
    if (!(flag1&flag2)) return;
    num++;
    printf("Clique %d &:",num);
    for (set<int>::iterator itr=S.begin(); itr!=S.end(); ++itr)
        if (*itr<=8) cout<<'g'<<*itr<<',';
        else cout<<'m'<<*itr-8<<',';
    cout<<"\\\\"<<endl;
}
        

void init()
{
    //construct the graph, you can use printw to check it
    w[1][1+8]=w[1][2+8]=w[1][7+8]=1;
    w[2][1+8]=w[2][2+8]=w[2][7+8]=w[2][8+8]=1;
    w[3][1+8]=w[3][2+8]=w[3][3+8]=w[3][7+8]=w[3][8+8]=1;
    w[4][1+8]=w[4][3+8]=w[4][7+8]=w[4][8+8]=w[4][9+8]=1;
    w[5][1+8]=w[5][2+8]=w[5][4+8]=w[5][6+8]=1;
    w[6][1+8]=w[6][2+8]=w[6][3+8]=w[6][4+8]=w[6][6+8]=1;
    w[7][1+8]=w[7][3+8]=w[7][4+8]=w[7][5+8]=1;
    w[8][1+8]=w[8][3+8]=w[8][4+8]=w[8][6+8]=1;
    for (int i=1; i<=17; ++i)
        for (int j=1; j<=17; ++j)
        {
            w[i][j]|=(w[j][i]|((!((i<=8)^(j<=8)))&(i!=j)));
            if (w[i][j]) n[i].insert(j);
        }
}

void bk(set <int>R,set <int> P,set<int> X)
{
    //bron-kerbosch algo
    if (P.empty()&X.empty()) printClique(R);
    set<int> itrP=P;
    for (set<int>::iterator itr= itrP.begin(); itr!=itrP.end(); ++itr)
    {
        set<int> Rt=R,Pt,Xt;
        Rt.insert(*itr);
        set_intersection(P.begin(),P.end(),n[*itr].begin(),n[*itr].end(),inserter(Pt,Pt.begin()));
        set_intersection(X.begin(),X.end(),n[*itr].begin(),n[*itr].end(),inserter(Xt,Xt.begin()));
        bk(Rt,Pt,Xt);
        P.erase(*itr);
        X.insert(*itr);
    }
}
    

int main()
{
    init();
    for (int i=1; i<=17; ++i)
        P.insert(i);
    bk(R,P,X);
    return 0;
}
