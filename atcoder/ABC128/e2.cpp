#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)m;i<(int)n;++i)
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7;

int main()
{
    int n,q;
    cin>>n>>q;
    int s[n],t[n],x[n];
    rep(i,n) cin>>s[i]>>t[i]>>x[i];
    set<pair<int,int>> st;
    rep(i,q)
    {
        int a;
        cin>>a;
        st.insert({a,i});
    }
    st.insert({inf,-1});
    vector<>
    return 0;
}
