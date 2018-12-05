#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int x1,x2,x3,x4,y1,y2,y3,y4;
int dx,dy;
int main()
{
    cin>>x1>>y1>>x2>>y2;
    dx = x2-x1;
    dy = y2-y1;
    x3 = x2-dy;
    y3 = y2+dx;
    x4 = x3-dx;
    y4 = y3-dy; 
    cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4<<endl;
    return 0;
}
