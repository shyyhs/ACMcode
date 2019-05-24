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

struct Point2D {
  int x;
  int y;
  Point2D(int tx=0,int ty=0)
  {
      x =tx;
      y =ty;
  }
};

Point2D s[20000];
int t=0;

bool cmp(Point2D a, Point2D b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool check_cross(int x1, int y1, int x2, int y2)
{
    int cross_ans = x1*y2 - x2*y1;
    return (cross_ans <= 0);
}

int solution(vector<Point2D> &A) {
    sort(A.begin(),A.begin()+A.size(),cmp);
    s[t++] = A[0];
    for (int i=1; i<A.size(); ++i)
    {
        while (1)
        {
            if (t<=1)
            {
                s[t++] = A[i];
                break;
            }
            int x1 = s[t-1].x - s[t-2].x;
            int y1 = s[t-1].y - s[t-2].y;
            int x2 = A[i].x - s[t-1].x;
            int y2 = A[i].y - s[t-1].y;
            if (check_cross(x1, y1, x2, y2))
            {
                s[t++]=A[i];
                break;
            }
            t--;
        }
    }
    return t;
}

int main()
{
    vector<Point2D> A;
    A.push_back(Point2D(3,2));
    A.push_back(Point2D(6,3));
    A.push_back(Point2D(2,5));
    A.push_back(Point2D(5,2));
    A.push_back(Point2D(1,1));
    A.push_back(Point2D(4,4));
    sort(A.begin(),A.begin()+A.size(),cmp);
    for (int i=0; i<A.size(); ++i)
        cout<<A[i].x<<' '<<A[i].y<<endl;
    cout<<solution(A)<<endl;
    return 0;
}
