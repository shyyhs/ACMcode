#include<iostream>

using namespace std;

struct tree
{
    int x;
    tree *l;
    tree *r;
}

int f[120000];

int dp(tree *T,int *f)
{
    if (T==0) return 0;
    if (f[T.x]) return f[T.x];
    int ansl = solution(T.l), ansr = solution(T.r);
    return  f[T.x]=(ansl == ansr)?ansl+1:(min(ansl,ansr)+1);
}

int solution(tree *T)
{
    return max(dp(T,f),max(solution(T.l,f),solution(T.r,f)));
}

int main()
{
    cout<<solution(T)<<endl;
    return 0;
}
