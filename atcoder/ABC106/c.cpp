#include<iostream>
#include<cstdio>
using namespace std;
char s[150];
char c;
int t=0;
long long k;
int main()
{
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n') break;
        s[t++]=c;
    }
    cin>>k;
    for (int i=0; i<t; ++i)
    {
        if (s[i]=='1')
        {
            k-=1;
            if (k==0)
            {
                cout<<1<<endl;
                break;
            }
        }
        else
        {
            cout<<s[i]<<endl;
            break;
        }
    }
    return 0;
}
