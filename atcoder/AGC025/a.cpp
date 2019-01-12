#include<iostream>
using namespace std;
int n;

int sumN(int x)
{
    int t=0;
    while (x)
    {
        t+=(x%10);
        x/=10;
    }
    return t;
}

int main()
{
    int minAns=10000000;
    cin>>n;
    for (int i=1; i<n; ++i)
    {
        int t=sumN(i)+sumN(n-i);
        if (t<minAns)
            minAns=t;
    }
    cout<<minAns<<endl;
    return 0;
}
