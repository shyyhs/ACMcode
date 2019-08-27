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
int v[100];
int ans;

int s[100];
int t;

int main()
{
    int max_ans = -1000000000;
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
        cin>>v[i];
    for (int i=0; i<=n; ++i)
    {
        for (int j=n+1; j>i; --j)
        {
            t=0;
            for (int o=1; o<=i; ++o)
                s[t++]=v[o];
            for (int o=n; o>=j; --o)
                s[t++]=v[o];
            int nowk = i+(n-j+1);
            if (nowk>k) continue;
            sort(s,s+t);
            int nowans=0;
            for (int o=0; o<t; ++o)
            {
                if (s[o]>0) nowans+=s[o];
                if (s[o]<0)
                {
                    if (nowk<k) 
                    {
                        nowk++;
                    }
                    else
                    {
                        nowans+=s[o];
                    }
                }
            }
            if (nowans>max_ans)
                max_ans=nowans;
        }
    }
    cout<<max_ans<<endl;
    return 0;
}

