#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<random>
using namespace std;

int n;
int x[1000],y[1000],h[1000];
int Cx,Cy;
int H[1000];
void init()
{
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
        scanf("%d %d %d",&x[i],&y[i],&h[i]);

}

void work()
{
    for (Cx=0; Cx<=100; ++Cx)
        for (Cy=0; Cy<=100; ++Cy)
        {
            int flag=1,Htmp=0,firstHFlag=0;
            for (int i=0; i<n; ++i)
            {
                if (h[i]>0)
                {
                    int HCheck=h[i]+abs(Cx-x[i])+abs(Cy-y[i]);
                    if (firstHFlag==0)
                    {
                        firstHFlag=1;
                        Htmp=HCheck;
                    }else if(HCheck!=Htmp)
                    {
                        flag=0;
                        break;
                    }
                }else
                {
                    if (firstHFlag==1 && Htmp-abs(x[i]-Cx)-abs(y[i]-Cy)>0)
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag&&Htmp>=1) printf("%d %d %d\n",Cx,Cy,Htmp);
        }
}


int main()
{
    init();
    work();

    return 0;
}

