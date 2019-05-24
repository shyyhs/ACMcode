/*
 By shyyhs
Github: https://github.com/shyyhs/
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#define ll long long
using namespace std;
FILE* fin;
FILE* fout;

void work()
{

}
void init()
{
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&k);
    suma[0]=0;
    for (int i=1; i<=n; ++i)
    {
        fscanf(fin,"%c",&c);
        while (c!='S' && c!='.') fscanf(fin,"%c",&c);
        a[i]=(c=='S');
        suma[i]=suma[i-1]+(1-a[i]);
    }
}

int main(int argc, char *argv[])
{
    fin = fopen(argv[1],"r");
    init();    
    work();

    return 0;
}
