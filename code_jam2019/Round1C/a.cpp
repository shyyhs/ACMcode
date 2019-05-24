#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<ctime>
#include<algorithm>
#define ll long long 
using namespace std;

int n;
int loc[600];
int w[600][600];
int max_len = 0;
int res_flag=0;
int ct,t;
char c;
int flag[50][50];

int change(char c)
{
    if (c=='R') return 0;
    if (c=='P') return 1;
    if (c=='S') return 2;
    return 0;
}

char change_rev(int x)
{
    if (x==0) return 'R';
    if (x==1) return 'P';
    if (x==2) return 'S';
    return 0;
}

int win(int left, int right)
{
    if (left==right) return 0;
    if (left == 0)
    {
        if (right == 1) return -1;
        if (right == 2) return 1;
    }
    if (left == 1)
    {
        if (right == 0 ) return 1;
        if (right == 2) return -1;
    }
    if (left == 2)
    {
        if (right ==0) return -1;
        if (right ==1) return 1;
    }
    return -1;
}

bool win_all(int x1, int x2)
{
    memset(flag,0,sizeof(flag));
    int t1=0,t2=0;
    for (int i=0; i<max_len; ++i)
    while (flag[t1][t2]==0)
    {
        flag[t1][t2]=1;
        int now = win(w[x1][t1],w[x2][t2]);
        if (now==-1) return 0;
        if (now==1) return 1;
        t1+=1; t2+=1;
        if (t1>=loc[x1]) t1=0;
        if (t2>=loc[x2]) t2=0;
    }
    return 0;
}


void read_one(int x)
{
    while (1)
    {
        int tp = scanf("%c",&c);
        if (tp == EOF) break;
        
        if (c=='\n' && loc[x]>0) break;
        while (c!='R' && c!='P' && c!='S')
            tp=scanf("%c",&c);
        if (tp == EOF) break;
        w[x][loc[x]++]=change(c);
    }
}

int test()
{
    for (int i=1; i<=n; ++i)
        if (win_all(0,i)!=1)
            return 0;
    return 1;
}

void print_res(int res_flag)
{
    cout<<"Case #"<<ct<<": ";
    if (res_flag == 0)
        cout<<"IMPOSSIBLE"<<endl;
    else
    {
        for (int i=0; i<max_len; ++i)
            cout<<change_rev(w[0][i]);
        cout<<endl;
    }
}


void dfs(int now)
{
    if (res_flag ==1) return;
    if (now==max_len)
    {
        loc[0]=max_len;
        if (test() == 1)
        {
            res_flag = 1;
            print_res(res_flag);
        }
    }else
    {
        for (int i=0; i<3; ++i)
        {
            w[0][now]=i;
            dfs(now+1);
        }
    }
}

void solve()
{
    memset(loc,0,sizeof(loc));
    n = 0;
    memset(w,0,sizeof(w));
    max_len = 5;
    res_flag = 0;
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        read_one(i);
    }
    dfs(0);
    if (res_flag==0)
        print_res(res_flag);

}

int main()
{
    int t2;
    cin>>t2;
    for (ct =1; ct<=t2; ++ct)
    {
        solve();
    }
    return 0;
}

