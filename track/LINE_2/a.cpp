#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int n,k,q;
int loc[110000]; // loc[i] = cpu in location i 
int cup[110000]; // cpu[i] = location of cpu[i] 
int flag[110000]; 

void init(char *argv[])
{
    freopen(argv[1], "r", stdin);
    scanf("%d %d",&n,&k);
    scanf("%d",&q);
    for (int i=1; i<=n; ++i)
        loc[i] = i;
    for (int i=1; i<=q; ++i)
    {
        int s,t;
        scanf("%d %d",&s,&t);
        loc[s]=loc[s]^loc[t];
        loc[t]=loc[s]^loc[t];
        loc[s]=loc[s]^loc[t];
    }

    for (int i=1; i<=n; ++i)
        cup[loc[i]] = i; //reverse function of loc
}


void solve()
{
    int ball=1; // where the ball is
    bool round_flag=0;
    flag[1]=1;
    for (int turn=2; k>0; turn++)
    {
        k--;
        ball=cup[ball];

        if (round_flag == 0)
        {
            if (flag[ball] == 0)
                flag[ball] = turn;
            else
            {
                int round = turn - flag[ball];
                k = k % round;
                round_flag = 1;
            }
        }
    }
    cout << ball << endl;
}


int main(int argc, char*argv[])
{
    init(argv);
    solve();
    return 0;
}
