#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;


int n,m,a,b,c;
priority_queue<pair<int,int>> q;


int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
    {
        cin >> a;
        q.push(make_pair(a,1));
    }
    for (int i=1; i<=m; ++i)
    {
        cin >> b >> c;
        q.push(make_pair(c,b));
    }
    while (q.empty() == 0)
    {
    pair<int,int> tmp = q.top();
    q.pop();
    cout<<tmp.first<<' '<<tmp.second<<endl;
    }
    return 0;
}
