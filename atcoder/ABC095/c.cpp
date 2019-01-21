#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#include<set>
#include<vector>
#define ll long long
#define INTMAX 2147483647
using namespace std;
size_t n,m;
set<int> P;
vector<vector<double>> w;

void pnt()
{
    for (size_t i=0; i<w.size(); ++i)
    {
        for (size_t j=0; j<w[0].size(); ++j)
            printf("%0.2lf\t",w[i][j]);
        cout<<endl;
    }
    cout<<"result z:"<<' '<<-w[0][m-1]<<endl;
}

bool pivot(pair<size_t,size_t> &p)
{
    int x=0,y=0;
    double cmax=-INTMAX;
    double cmin=INTMAX;
    vector<double> C = w[0];
    vector<double> B;
    for (size_t i=0; i<n; ++i)
        B.push_back(w[i][m-1]);
    //find y
    for (size_t i=0; i<C.size(); ++i)
        if (C[i]<cmin && P.find(i)==P.end())
        {
            cmin=C[i];
            y=i;
        }
    //cout<<"cmax"<<' '<<cmax<<endl;
    //check quit
    if (cmin>0) return 0;
    //find x
    double bmin=INTMAX;
    for (size_t i=1; i<n; ++i)
    {
        if (w[i][y]!=0 && B[i]/w[i][y]<bmin)
        {
            bmin = B[i]/w[i][y];
            x=i;
        }
    }
    p = make_pair(x,y);
    for (set<int>::iterator it = P.begin(); it!=P.end(); it++)
        if (w[x][*it]!=0)
        {
            P.erase(*it);
            break;
        }
    P.insert(y);
    return 1;
}


void gaussian(pair<size_t,size_t> p)
{
    size_t x = p.first;
    size_t y = p.second;
    double norm = w[x][y];

    for (int i=0; i<m; ++i)
        w[x][i]/=norm;

    for (int i=0; i<n; ++i)
        if (i!=x)
        {
            norm = w[i][y];
            for (int j=0; j<m; ++j)
                w[i][j]-=norm*w[x][j];
        }
}


double solve()
{
    pair<size_t,size_t> t;
    for (int i=0; i<5; ++i)
    {
        if (pivot(t)==0) return -w[0][m-1];
        pnt();
        cout<<t.first<<' '<<t.second<<endl;
        for (set<int>::iterator it=P.begin(); it!=P.end(); it++)
            cout<<*it<<' ';
        cout<<endl;

        gaussian(t);
    }
}

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    n = 3;
    m = 6;
    for (int i=0; i<n; ++i)
    {
        vector<double> tmp;
        for (int j=0; j<m; ++j)
            tmp.push_back(0);
        w.push_back(tmp);
    }
    w[0][0]=-a; w[0][1]=-b; w[0][2]=-c;
    w[1][0]=1; w[1][2]=0.5; w[1][3]=1; w[1][5]=x;
    w[2][1]=1; w[2][2]=0.5; w[2][4]=1; w[2][5]=y;
    for (int i=0; i<n-1; ++i)
        P.insert(m-i-2);

    printf("%0.0lf\n",solve());
    return 0;
}

