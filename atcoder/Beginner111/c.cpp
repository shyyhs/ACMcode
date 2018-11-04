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
int a[200000],b[200000];
struct T
{
    int num,fre;
}A[200000],B[200000];
int lenA,lenB;

void init()
{
    cin>>n;
    n/=2;
    for (int i=0; i<n; ++i)
        cin>>a[i]>>b[i];
}


void check(int a[200000],T A[200000],int &len)
{
    int flag[200000]={0};
    for (int i=0; i<n; ++i)
        flag[a[i]]++;
    for (int i=0; i<150000; ++i)
        if (flag[i])
        {
            A[len].fre=flag[i];
            A[len].num=i;
            len++;
        }
}

void work()
{
    check(a,A,lenA);
    check(b,B,lenB);
    sort(A,A+lenA,[](T a, T b){return a.fre>b.fre;});
    sort(B,B+lenB,[](T a, T b){return a.fre>b.fre;});
    //for (int i=0; i<lenA; ++i)
        //cout<<A[i].num<<' '<<A[i].fre<<endl;
    //for (int i=0; i<lenB; ++i)
        //cout<<B[i].num<<' '<<B[i].fre<<endl;
    if (A[0].num!=B[0].num)
    {
        cout<<n*2-A[0].fre-B[0].fre<<endl;return;
    }
    cout<<min(n*2-A[0].fre-B[1].fre,n*2-A[1].fre-B[0].fre);
}


int main()
{
    init();
    work();
    return 0;
}

