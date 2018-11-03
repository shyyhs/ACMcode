#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int n,a[200000];
int s[400000];
int left_p,right_p,min_start,max_start;
long long sum;
bool flag=0;
long long calcu(int *a)
{
    left_p=right_p=200000;
    if (n%2==1) s[left_p--]=a[0],min_start=1;else min_start=0;
    right_p++;
    max_start = n-1;
    while (min_start<=max_start)
    {
        if(flag==0)
        {
        s[left_p--] = a[max_start--];
        if (min_start<=max_start) s[right_p++] = a[max_start--];
        }else
        {
            s[left_p--]=a[min_start++];
           if (min_start<=max_start) s[right_p++]=a[min_start++];
        }
        flag=1^flag;
    }
    long long sum_temp=0;
    for (int i=left_p+1; i<=right_p-2; ++i)
    {
        sum_temp+=abs(s[i]-s[i+1]);
    }
    return sum_temp;
}

//struct greater
//{
    //template<class T>
        //bool operator()(T const &a, T const &b) const{return a>b;}
//};

int main()
{
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
        scanf("%d",&a[i]);
    sort(a,a+n);
    sum = calcu(a);
    sort(a,a+n,greater<int>());
    sum = max(sum,calcu(a));
    printf("%lld\n",sum);
    return 0;
}
