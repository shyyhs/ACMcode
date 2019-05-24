#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define ll long long

using namespace std;

int w[120000][2]={0};
char c[240000];
int t=0;
string solution(int U, int L, vector<int> &C) 
{
    bool flag = 1;
    for (int i=0; i<C.size(); ++i)
    {
        if (C[i]==0)
        {
            w[i][0]=w[i][1]=0;
        }
        else if (C[i]==2)
        {
            w[i][0]=w[i][1]=1;
            U--; L--;
        }
        else if (C[i]==1)
        {
            if (U>0) 
            {
                w[i][0]=1; w[i][1]=0;
                U--;
            }else if (L>0)
            {
                w[i][0]=0; w[i][1]=1;
                L--;
            }else
            {
                flag = 0;
            }
        }
    }
    if (U>0 || L>0) flag = 0;
    if (flag == 0)
        return "IMPOSSIBLE";
    for (int i=0; i<2; ++i)
    {
        for (int j=0; j<C.size(); ++j)
            c[t++]=('0'+w[j][i]);
        if (i==0) c[t++]=',';
    }
    c[t++]='\0';
    return c;
}

