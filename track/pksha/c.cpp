#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define ll long long

using namespace std;

int n = 0;
int start_point = 0;

struct node
{
    int y,next;
};
node e[450000];
int top=1;
int loc[210000];

void add_edge(int x, int y)
{
    e[top].y = y;
    e[top].next = loc[x];
    loc[x] = top;
    top++;
}

int l,r,x,y;
int q[800000];
int d[800000];
bool v[800000];
int now;


vector<int> bfs()
{
    l = 0;
    r = 0;
    d[start_point] = 0;
    v[start_point] = 1;
    q[r++] = start_point;
    while (l<r)
    {
        x = q[l++];
        for (int now=loc[x]; now; now=e[now].next)
        {
            y = e[now].y;
            if (v[y] == 1) continue;
            v[y] = 1;
            d[y] = d[x] + 1;
            //cout<<x<<' '<<y<<' '<<d[x]<<' '<<d[y]<<endl;
            q[r++] = y;
        }
    }
    //for (int i=0; i<n; ++i)
    //    cout<< d[i] <<' ';
    //cout<<endl;

    vector<int> ans;
    for (int i=0; i<n-1; ++i)
        ans.push_back(0);
    for (int i=0; i<n; ++i)
        if (i!=start_point)
            ans[d[i]-1]++;
    return ans;
}


vector<int> solution(vector<int> &T) {
    n = T.size();
    for (int i=0; i<n; ++i)
    {
        if (T[i]==i)
        {
            start_point = i;
        }else
        {
            add_edge(T[i],i);
            add_edge(i,T[i]);
        }
    }
    return bfs();
}

//int main()
//{
//    vector<int> T={9, 1, 4, 9, 0, 4, 8, 9, 0, 1};
//    vector<int> D = solution(T);
//    cout<< start_point << endl;
//    for (int i=0; i<D.size(); ++i)
//        cout<<D[i]<<' ';
//    return 0;
//}
