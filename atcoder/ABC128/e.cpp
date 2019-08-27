#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;
set<int> q;

int findMax(set<int> my_set) 
{ 
  
    // Get the maximum element 
    int max_element; 
    if (!my_set.empty()) 
        max_element = *my_set.end(); 
  
    // return the maximum element 
    return max_element; 
} 

struct node
{
    int s,t,x;
};

struct node2
{
    int loc;
    int ai;
    int sflag;
};

node2 b[700000];
int t;

node a[600000];

int n,m;
int d[600000];

bool cmp(node a1,node a2)
{
    if (a1.s!=a2.s) return a1.s<a2.s;
    return a1.t<a2.t;
}

bool cmp2(node2 a1,node2 a2)
{
    return a1.loc<a2.loc;
}

int findMin(set<int> my_set)
{

    // Get the minimum element
    int min_element;
    if (!my_set.empty())
        min_element = *my_set.begin();

    // return the minimum element
    return min_element;
}


int main()
{
    cin>>n>>m;
    for (int i=0; i<n; ++i)
    {
        scanf("%d %d %d",&a[i].s,&a[i].t,&a[i].x);
        a[i].s-=a[i].x;
        a[i].t-=a[i].x;

        b[t].loc = a[i].s;
        b[t].ai=i;
        b[t].sflag=1;
        t++;

        b[t].loc = a[i].t;
        b[t].ai=i;
        b[t].sflag=0;
        t++;
    }
    for (int i=0; i<m; ++i) scanf("%d",&d[i]);
    sort(b,b+t,cmp2);

    int qi=0;
    for (int i=0; i<t; ++i)
    {
        if (qi==m) break; 
        while (b[i].loc>d[qi] && qi!=m)
        {
                if (q.empty())
                {
                    cout<<-1<<endl;
                }else
                {
                    int tmp = findMin(q);
                    cout<<tmp<<endl;
                }
            qi++;
        }
        if (qi>=m) break;
        if (b[i].loc<=d[qi])
        {
            if (b[i].sflag == 1)
                q.insert(a[b[i].ai].x);
            if (b[i].sflag==0)
                q.erase(a[b[i].ai].x);
        }
    }
    while (qi<m)
    {
        cout<<-1<<endl;
        qi++;
    }
    return 0;
}

