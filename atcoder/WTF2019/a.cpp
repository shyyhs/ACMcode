#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int a[1000];
int loc;
int s[100000];
int t;
int ansFlag=0;

int main()
{
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    loc=n;
    int flag=1;

    while (flag)
    {
        flag=0;
        for (int i=1; i<=n; ++i)
        {
            if (i==loc && k==0)
            {
                s[t++]=i;
                ansFlag=1;
                flag=0;
                break;
            }
            if (i==loc && k!=0)
            {
                k--;
                loc=i-1;
                if (loc==0) loc=n;
            }
            if (a[i]>0) 
            {
                flag=1;
                a[i]--;
                s[t++]=i;
            }
            if (a[i]==0 && k>1)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    if (ansFlag)
    {
        cout<<t<<endl;
        cout<<s[0];
        for (int i=1; i<t; ++i)
            cout<<' '<<s[i];
        cout<<endl;
    }else
    {
        cout<<-1<<endl;
        return 0;
    }
    return 0;
}
            
