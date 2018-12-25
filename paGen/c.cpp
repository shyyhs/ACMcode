#include<iostream>
using namespace std;
int t,b,ans;
int main()
{
    cin>>b;
    while (b)
    {
        t = b*2;
        if (t%3==0)
        {
            b=t/3;
            ans++;
            continue;
        }
        t=b*2+1;
        if (t%3==0)
        {
            b=t/3;
            ans++;
            continue;
        }
        break;
    }
    cout<<ans<<endl;
    return 0;
}
