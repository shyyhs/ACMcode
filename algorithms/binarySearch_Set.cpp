#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
int n;
int a[300000];
int MAXN = 2147483647;

map<ll,int> mp;

ll len=0;

void init()
{
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
        scanf("%d",&a[i]);
}

void clearLen(int i)
{
    for (auto it=mp.begin(); it!=mp.end();)
    {
        if (it->first>len) it = mp.erase(it);
        else it++;
    }
}

bool addState(int k)
{
    int nowLen=len;
    while (nowLen>=1)
    {
        auto it = mp.find(nowLen);
        if (it!=mp.end())
        {
            if (mp[nowLen]<k-1)
            {
                mp[nowLen]+=1;
                return 1;
            }else
            {
                mp.erase(it);
                nowLen-=1;
            }
        }else
        {
            mp[nowLen]=1;
            if (mp[nowLen]>k-1) return 0;
            return 1;
        }
    }
    return 0;
}

bool check(int ind)
{
    mp.clear();
    len=a[0];
    
    if (ind<1) return 0;
    for (int i=1; i<n; ++i)
    {
        len=a[i];
        if (a[i]>a[i-1])
        {
        }
        else
        {
            clearLen(i);
            bool flag=addState(ind);
            if (flag==0)
                return 0;
        }
    }
    return 1;
}

int binarySearch(int l,int r)
{
    int mid=0;
    while (l<=r)
    {
        mid=l+(r-l)/2;
        bool checkMid=check(mid);
        bool checkPre=check(mid-1);
        if (checkMid==1 && checkPre==0)
            return mid;
        if (checkMid)
            r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main()
{
    init();
    cout<<binarySearch(1,MAXN)<<endl;
    return 0;
}

