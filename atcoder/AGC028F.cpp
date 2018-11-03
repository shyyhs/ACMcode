#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[510][510],f[510][510][510];
char c;
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
        {
            scanf("%c",&c);
            if (c=='\n') scanf("%c",&c);
            a[i][j]=(c=='#')?-1:int(c)-int('0');
        }
    memset(f,0,sizeof(f));
    for(int i=n-1; i>=0; --i)
        for (int j=n-1; j>=0; --j)
        {
            if (i+1<n && a[i+1][j]>=0)
    return 0;
}
