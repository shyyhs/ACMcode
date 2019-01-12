#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int len=0;
char s[30];
bool flag[300];
char c;

int findDec()
{
    for (int i=len-1; i>=0; --i)
    {
        if (i==0) return -1;
        if (s[i-1]>s[i]) continue;
        if (s[i-1]<s[i]) return i-1;
    }
    return -1;
}

void geneLoc(int loc)
{
    memset(flag,0,sizeof(flag));
    for (int i=0; i<loc; ++i)
    {
        cout<<s[i];
        flag[s[i]]=1;
    }
    for (char c=s[loc]+1; c<='z'; ++c)
        if (flag[c]==0)
        {
            cout<<c<<endl;
            break;
        }
}


int main()
{
    while (scanf("%c",&c)!=EOF)
    {
        if (c>='a' && c<='z')
            s[len++]=c;
        else break;
        flag[c]=1;
    }
    if (len<26)
    {
        cout<<s;
        for (char c='a'; c<='z'; ++c)
            if (flag[c]==0)
            {
                cout<<c<<endl;
                break;
            }
    }
    if (len==26)
    {
        int loc=findDec();
        if (loc==-1)
        {
            cout<<loc<<endl;
        }else
        {
            geneLoc(loc);
        }
    }
    return 0;
}
