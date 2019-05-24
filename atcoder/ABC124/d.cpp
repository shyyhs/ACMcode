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
int n,k;
int s[120000];
char c;
struct st
{
    int len, flag;
};

st bk[120000];
int t=0;

int main()
{
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
    {
        scanf("%c",&c);
        while  (c!='0' && c!='1') 
            scanf("%c",&c);
        s[i]=c-'0';
        if (t==0 || s[i]!=s[i-1])
        {
            t+=1;
            bk[t].len=1;
            bk[t].flag=s[i];
        }else
        {
            bk[t].len++;
        }
    }
    int now_rev = 0;
    int start_pos = 0;
    int end_pos = 0;

    int ans = 0;
    int tans = 0;

    if (bk[1].flag == 0)
    {
        bk[0].flag=1;
        start_pos=0;
    }else
    {
        start_pos=1;
    }
    for (int i=1; i<=t; ++i)
    {
        if (bk[i].flag == 0 && now_rev<k)
        {
            tans += bk[i].len;
            now_rev+=1;
        }else if (bk[i].flag==0 && now_rev==k)
        {
            if (bk[start_pos].flag==0)
            {
                tans-=bk[start_pos].len;
                start_pos+=1;
            }else 
            {
                tans-=bk[start_pos].len;
                start_pos+=1;
                tans-=bk[start_pos].len;
                start_pos+=1;
            }
            tans += bk[i].len;
        }else if (bk[i].flag == 1)
        {
            tans += bk[i].len;
        }
        ans = max(ans,tans);
    }
    cout<<ans<<endl;



    return 0;
}

