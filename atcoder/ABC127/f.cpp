#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;
int q;
ll a,b,B,type;
ll sum1, sum2;
priority_queue<ll> q1;
priority_queue<ll, vector<ll>, greater<ll>> q2;
int main()
{
    cin >> q;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin>>a>>b;
            B+=b;
            if (q2.empty() || a>=q2.top())
            {
                q2.push(a); sum2+=a;
                q2.push(a); sum2+=a;
                a = q2.top(); q2.pop(); sum2-=a;
                q1.push(a); sum1+=a;
            }else
            {
                q1.push(a); sum1+=a;
                q1.push(a); sum1+=a;
                a = q1.top(); q1.pop(); sum1-=a;
                q2.push(a); sum2+=a;
            }
        }else
            cout<<q1.top()<<' '<<(sum2-sum1)/2+B<<endl;
    }
    return 0;
}


