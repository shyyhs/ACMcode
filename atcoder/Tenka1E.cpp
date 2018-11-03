#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

void init(int &H,int &W, int w[][1000])
{
    scanf("%d %d",&H,&W);
    char c;
    for (int i=0; i<H; ++i)
        for (int j=0; j<W; ++j)
        {
            scanf("%c",&c);
            while (c!='.' && c!='#') scanf("%c",&c);
            w[i][j]=(c=='#')?1:0;
        }
}
int dist(int x,int y,int xx,int yy)
{
    return abs(x-xx)+abs(y-yy);
}

long long count(int H,int W, int w[][1000])
{
    long long sum=0;
    int x1,x2,x3,x4,y1,y2,y3,y4,x5,x6,x7,x8,y5,y6,y7,y8;
    int d;
    for (int i=0; i<H; ++i)
        for (int j=0; j<W; ++j)
            if (w[i][j])
            for (int i2=0; i2<H; ++i2)
                for (int j2=0; j2<W; ++j2)
                if (w[i2][j2] && (i!=i2 || j!=j2))
                {
                    d = dist(i,j,i2,j2);
                    y1=(j2-j+i+i2+2*d)/2;
                    x1=y1+j-i-d;
                    y2=(j2-j+i+i2)/2;
                    x2=y2+j-i-d;
                    y3=y2;
                    x3=y3+j-i+d;
                    y4=y2-d;
                    x4=y4+j-i+d;
                    y5=(j+i-j2+i2+2*d)/2;
                    x5=-(y5-j-i-d);
                    y6=(j+i-j2+i2)/2;
                    x6=-(y6-j-i-d);
                    y7=(j+i-j2+i2)/2;
                    x7=-(y7-j-i+d);
                    y8=(j+i-j2+i2-2*d)/2;
                    x8=-(y8-j-i+d);
                    sum+=(y1>0 && x1>0 && w[y1][x1] &&dist(y1,x1,i,j)==d)+(y2>0 && x2>0 && w[y2][x2]&&dist(y2,x2,i,j)==d)+(y3>0 && x3>0 && w[y3][x3]&&dist(y3,x3,i,j)==d)+(y4>0 && x4>0 && w[y4][x4]&&dist(y4,x4,i,j)==d)+
                        (y5>0 && x5>0 && w[y5][x5]&&dist(y5,x5,i,j)==d)+(y6>0 && x6>0 && w[y6][x6]&&dist(y6,x6,i,j)==d)+(y7>0 && x7>0 && w[y7][x7]&&dist(y7,x7,i,j)==d)+(y8>0 && x8>0 && w[y8][x8]&&dist(y8,x8,i,j)==d);
                }
    return sum/6;
}


int main()
{
    int H,W;
    int w[1000][1000];
    init(H,W,w);
    printf("%lld\n",count(H,W,w));
    return 0;
}

