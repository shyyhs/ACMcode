#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int ele1,ele2;
int s[1000][1000];
int s_pointer[1000];

void func_print(int s[][1000],int s_size,int s_num)
{
    printf("%d\n",s_num);
    for (int i=0; i<s_num; ++i)
    {
        printf("%d ",s_size);
        for (int j=0; j<s_size; ++j)
            printf("%d ",s[i][j]);
        printf("\n");
    }
}
void func_cal(int n,int s_size,int s_num)
{
    int tail=1;
    for (int i=0; i<s_num; ++i)
    {
        int size_tmp=0;
        for (int j=0; j<i; ++j)
            s[i][size_tmp++]=s[j][s_pointer[j]++];
        while (size_tmp<s_size)
            s[i][size_tmp++]=tail++;
        s_pointer[i]=(i==0)?0:s_pointer[i-1];
    }
}

int main()
{
    cin>>n;
    ele1=int(trunc(sqrt(2*n)));
    ele2=2*n/ele1;
    if (ele1*ele2!=2*n || (ele2-ele1!=1)) {cout<<"No"<<endl; return 0;} else cout<<"Yes"<<endl;
    func_cal(n,ele1,ele2);
    func_print(s,ele1,ele2);
    return 0;
}
    
