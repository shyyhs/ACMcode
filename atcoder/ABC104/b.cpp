#include<iostream>
#include<cstdio>
using namespace std;
char s[20];
int t=0;
char c;
int ind;
int main()
{
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        s[t++]=c;
    }
    int f=1;
    if (s[0]!='A') f=0;
    int sum=0;
    for (int i=2; i<=t-1-1; ++i)
        if (s[i]=='C') 
        {
            ind=i;
            sum++;
        }
    
    if (sum!=1) f=0;
    for (int i=1; i<t; ++i)
        if (i!=ind)
        if (s[i]>='A' && s[i]<='Z')
            f=0;
    if (f==0) cout<<"WA"<<endl;
    else cout<<"AC"<<endl;
    return 0;
}

