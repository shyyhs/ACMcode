#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
char c;
char s1[200],s2[200];
int t1,t2;
int f=0;

bool check(int s)
{
    for (int i=0; i<t1; ++i)
        if (s1[(s+i)%t1]!=s2[i])
            return 0;
    return 1;
}

int main()
{
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        s1[t1++]=c;
    }
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        s2[t2++]=c;
    }
    for (int i=0; i<t1; ++i)
        if (check(i)) f=1;
    if (f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
    
