#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 1010
#define MAXChild 4
struct node
{
    int next[MAXChild];
    int fail;
    int flag;
    void init()
    {
        memset(next,0,sizeof(next));
        fail=0;
        flag=0;
    }
}trie[maxn];
int tot,inf;

int dp[maxn][maxn];
char c[4]={'A','C','G','T'};

int n;

void init()
{
    tot=0;
    trie[0].init();
    memset(dp,1,sizeof(dp));
    inf=dp[0][0];
}

int getnum(char x)
{
    for (int i=0; i<4; ++i)
        if (x==c[i]) return i;
    return 0;
}

void insert(char *str)
{
    int p=0,index;
    for (;*str!='\0';str++)
    {
        index=getnum(*str);
        if (trie[p].next[index]==0)
        {
            trie[++tot].init();
            trie[p].next[index]=tot;
        }
        p=trie[p].next[index];
    }
    trie[p].flag=1;
}

void build_fail()
{
    queue<int> Q;
    int p,son,cur,i;
    Q.push(0);
    while (!Q.empty())
    {
        p=Q.front();
        Q.pop();
        for (int i=0; i<4; ++i)
        {
            if (trie[p].next[i]!=0)
            {
                son=trie[p].next[i];
                cur=trie[p].fail;
                if (p==0)
                    trie[son].fail=0;
                else
                {
                    while (cur&&trie[cur].next[i]==0)
                        cur=trie[cur].fail;
                    trie[son].fail=trie[cur].next[i];
                    if (trie[trie[son].fail].flag)
                        trie[son].flag=1;
                }
                Q.push(son);
            }else
            {
                trie[p].next[i]=trie[trie[p].fail].next[i];
            }
        }
    }
}

char str[maxn],tmp[25];
int solve()
{
    dp[0][0]=0;
    int i,j,k,len=strlen(str+1);
    for (int i=1; i<=len; ++i)
        for (int j=0; j<=tot; ++j)
            if (dp[i-1][j]!=inf)
                for (k=0; k<4; ++k)
                {
                    int son=trie[j].next[k];
                    if (trie[son].flag==0)
                        dp[i][son]=min(dp[i][son],dp[i-1][j]+(getnum(str[i])!=k));
                }
    int ans=inf;
    for (int i=0; i<=tot; ++i)
        if (!trie[i].flag)
            ans=min(ans,dp[len][i]);
    return (ans==inf)?-1:ans;
}


int main()
{
    int T=0;
    while (scanf("%d",&n)&&n)
    {
        init();
        for (int i=0; i<n; ++i)
        {
            scanf("%s",tmp);
            insert(tmp);
        }
        build_fail();
        scanf("%s",str+1);
        printf("Case %d: %d\n",++T,solve());
    }
}
