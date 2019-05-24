#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
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
int dx[8]={-2,-2,-1,1,2,2,1,-1};
int dy[8]={1,-1,-2,-2,-1,1,2,2};
int n,m;
int nowx, nowy;
int x,y;

int l=0;
int r=0;
int q[12000000];

bool block[12000000];
bool visited[12000000];
int dis[12000000];

int start_point = 0;


int solution(vector< vector<int> > &A) {
    n = A.size();
    m = A[0].size();

    int end_point = (n-1)*m + (m-1);

    for (int i=0; i<A.size(); ++i)
        for (int j=0; j<A[i].size(); ++j)
            if (A[i][j] == 1)
                block[i*m + j] = 1;

    q[r++] = start_point;
    visited[start_point] = 1;
    dis[start_point] = 0;
    while (l<r)
    {
        nowx = q[l]/m;
        nowy = q[l]%m;
        l++;
        for (int i=0; i<8; ++i)
        {
            x = nowx+dx[i];
            y = nowy+dy[i];
            if (x>=0 && x<n && y>=0 && y<m)
                if (visited[x*m+y]==0 && block[x*m+y]==0)
                {
                    visited[x*m+y]=1;
                    dis[x*m+y]=dis[nowx*m+nowy]+1;
                    if (x*m+y == end_point)
                        return dis[end_point];
                    q[r++]=x*m+y;
                }
        }
    }
}

//int main()
//{
//    vector<int> a1 = {0,0,0};
//    vector<int> a2 = {0,0,1};
//    vector<int> a3 = {1,0,0};
//    vector<int> a4 = {0,0,0};
//    vector< vector<int> > A;
//    A.push_back(a1);
//    A.push_back(a2);
//    A.push_back(a3);
//    A.push_back(a4);
//    cout<<solution(A)<<endl;
//    return 0;
//}
