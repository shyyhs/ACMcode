#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
struct node
{
    int s,e;
};

node line[20000];

bool cmp(node a, node b)
{
    if (a.s!=b.s) return a.s<b.s;
    return a.e<b.e;
}

void init(char *argv[])
{
    freopen(argv[1], "r", stdin);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> line[i].s >> line[i].e;
}

void solve()
{
    int ans = 0;
    int now_ans = 0;
    int now_start=-20000, now_end=-20000;
    sort(line, line+n, cmp);
    for (int i=0; i<n; ++i)
    {
        if (line[i].s>now_end)
            now_start = line[i].s;
        now_end = line[i].e;
        now_ans = now_end - now_start;
        if (now_ans > ans)
            ans = now_ans;
    }
    cout<< ans << endl;
}

int main(int argc, char *argv[])
{
    init(argv);
    solve();
    return 0;
}

