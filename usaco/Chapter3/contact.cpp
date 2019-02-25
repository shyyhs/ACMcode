/*
ID: songskg2
PROG: contact
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;
int a,b,n;
char c;
char s[210000];
int t;
bool flag[210000];
struct node
{
    int l,r,c;
};
int now=0;
node tree[50000];
int treet=1;
int root=0;

int ans[210000];
int anst;

void addNode(int x)
{
    int now=root;
    int nowL=0;
    for (int i=1; i<=b; ++i)
    {
        if (x+i-1>=t) break;
        if (s[x+i-1]=='0')
        {
            if (tree[now].l==0)
                tree[now].l=treet++;
            now=tree[now].l;
        }else
        {
            if (tree[now].r==0)
                tree[now].r=treet++;
            now=tree[now].r;
        }
        if (i>=a)
            tree[now].c+=1;
    }
}

bool cmp(int a,int b)
{
    return a>b;
}
int outN=0;

int anss[20];
int ansst=0;
void prints()
{
    outN+=1;
    if (outN!=1) cout<<' ';
    for (int i=0; i<ansst; ++i)
        cout<<anss[i];
    if (outN==6)
    {
        cout<<endl;
        outN=0;
    }
}

void dfs(int now,int x,int nowlv,int lv)
{
    if (tree[now].c==x && nowlv==lv)
        prints();
    if (tree[now].l)
    {
        anss[ansst++]=0;
        dfs(tree[now].l,x,nowlv+1,lv);
        ansst--;
    }
    if (tree[now].r)
    {
        anss[ansst++]=1;
        dfs(tree[now].r,x,nowlv+1,lv);
        ansst--;
    }
}

void searchT(int x)
{
    int now=0;
    for (int lv=1; lv<=12; ++lv)
        dfs(now,x,0,lv);
}

int main()
{
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    cin>>a>>b>>n;
    bool wflag=1;
    while (scanf("%c",&c)!=EOF)
    {
        while (c!='0' && c!='1')
        {
            int ct=scanf("%c",&c);
            if (ct==EOF)
            {
                wflag=0;
                break;
            }
        }
        if (wflag==0) break;
            
        s[t++]=c;
    }
    
    for (int i=0; i<t; ++i)
    {
        addNode(i);
    }
    for (int i=0; i<treet; ++i)
    {
        if (flag[tree[i].c]==0)
        {
            flag[tree[i].c]=1;
            ans[anst++]=tree[i].c;
        }
    }
    sort(ans,ans+anst,cmp);
    for (int i=0; i<n; ++i)
        if (ans[i]>0)
    {
        cout<<ans[i]<<endl;
        searchT(ans[i]);
        if (outN!=0)
            cout<<endl;
        outN=0;
    }
    



    return 0;
}
