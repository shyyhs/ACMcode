#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int x[1100],y[1100];
int flag=1;

void printFun(int num,bool dir)
{
    if (abs(num)>15) return;
    for (int i=0; i<abs(num); ++i)
        if (num>0) cout<<(dir?'R':'U');else cout<<(dir?'L':'D');
    for (int i=0; i<(20-abs(num)%2-abs(num))/2; ++i)
        cout<<"RL";
}
void work()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cin>>x[i]>>y[i];
        if (flag<0) continue;
        flag=abs(x[i]+y[i])%2;
        if ((i>0)&&((abs(x[i-1]+y[i-1])%2)!=flag)) flag=-1;
    }
    if (flag<0) {cout<<-1<<endl; return;}
    m=40-flag;
    cout<<m<<endl;
    for (int i=0; i<m; ++i)
        cout<<1<<' ';
    cout<<endl;
    for (int i=0; i<n; ++i) 
    {
        printFun(x[i],1);printFun(y[i],0);
        if((abs(x[i])%2) && (abs(y[i])%2)) cout<<"RL";
        cout<<endl;
    }
}

int main()
{
    work();
    return 0;
}

