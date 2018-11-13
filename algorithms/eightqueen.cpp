#include<iostream>
using namespace std;
int n,sum=0,limit;

void eq(int col,int ld,int rd)
{
    if (col==limit) sum++;else
    for (int p,pos=limit&(~(col|ld|rd)); pos; pos-=p)
    {
        p=pos&(-pos);
        eq(col+p,(ld+p)>>1,(rd+p)<<1);
    }
}
    
int main()
{
    cin>>n;
    limit=(1<<n)-1;
    eq(0,0,0);
    cout<<sum<<endl;
    return 0;
}

