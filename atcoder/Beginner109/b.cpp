#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
char s[1000][100];
void init()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>s[i];
    for (int i=0; i<n; ++i)
        if (((i>0)&&s[i][0]!=s[i-1][strlen(s[i-1])-1]) || (i<n-1 && s[i][strlen(s[i])-1]!=s[i+1][0]))
        {
            cout<<"No"<<endl;
            return;
        }
    
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if(!strcmp(s[i],s[j])&&i!=j)
            {
                cout<<"No"<<endl;
                return;
            }
    cout<<"Yes"<<endl;

}

void work()
{

}


int main()
{
    init();
    work();
    return 0;
}

