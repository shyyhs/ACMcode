#include<iostream>
#include<algorithm>
using namespace std;
int n=5;
struct T
{
    int month;
    int day;
}a[5];
bool myfunc(T ai,T aj)
{
    if (ai.month!=aj.month) return ai.month<aj.month;
    else return ai.day<aj.day;
}
int main()
{
    for (int i=0; i<5; ++i)
    {
        a[i].month=(i/2);
        a[i].day=i;
    }
    sort(a,a+n,myfunc);
    for (int i=0; i<n; ++i)
        cout<<a[i].month<<' '<<a[i].day<<endl;
    return 0;
}
    
