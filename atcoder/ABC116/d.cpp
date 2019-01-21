#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
ll MAXF;
ll n,k;
struct T
{
    ll t,d;
}a[120000];
int bg[120000],ed[120000];
bool flag[120000];
ll nowt=0;
ll ans;

typedef struct
{
    int l,r;
}Tree;
Tree node[300000];
int father[300000];
ll add[300000];
ll maxV[300000];
int maxI[300000];

void build(int i,int l,int r)
{
    node[i].l=l;
    node[i].r=r;
    maxV[i]=0;
    if (l==r)
    {
        father[l]=i;
        maxV[i]=a[l].d;
        maxI[i]=l;
        return;
    }
    build(i<<1,l,(l+r)>>1);
    build((i<<1)+1,(1+((l+r)>>1)),r);
    int lid=i<<1,rid=i<<1|1;
    if (maxV[lid]>maxV[rid])
    {
        maxV[i]=maxV[lid];
        maxI[i]=maxI[lid];
    }else
    {
        maxV[i]=maxV[rid];
        maxI[i]=maxI[rid];
    }
    return;
}

void pushDown(int i,int l,int r)
{
    if (add[i])
    {
        add[i<<1]+=add[i];
        add[i<<1|1]+=add[i];
        int mid=(l+r)>>1;
        maxV[i<<1]+=add[i];
        maxV[i<<1|1]+=add[i];
        add[i]=0;
    }
}

void update(int i,int l,int r,int ql,int qr,ll addv)
{
    if (ql>r || qr<l) return;
    if (ql<=l && qr>=r)
    {
        maxV[i]+=addv;
        add[i]+=addv;
    }else
    {
        pushDown(i,l,r);
        int mid=(l+r)>>1;
        update(i<<1,l,mid,ql,qr,addv);
        update(i<<1|1,mid+1,r,ql,qr,addv);
        int lid=i<<1,rid=i<<1|1;
        if (maxV[lid]>maxV[rid])
        {
            maxV[i]=maxV[lid];
            maxI[i]=maxI[lid];
        }else
        {
            maxV[i]=maxV[rid];
            maxI[i]=maxI[rid];
        }
    }
}

ll query(int i,int l,int r,int ql,int qr,int& ind)
{
    if (ql>r || qr<l) return 0;
    if (ql<=l && qr>=r)
    {
        ind=maxI[i];
        return maxV[i];
    }
    pushDown(i,l,r);
    int mid = (l+r)>>1;
    int indl,indr;
    ll vl = query(i<<1,l,mid,ql,qr,indl);
    ll vr = query(i<<1|1,mid+1,r,ql,qr,indr);
    if (vl>vr)
    {
        ind=indl;
        return vl;
    }else
    {
        ind=indr;
        return vr;
    }
}

bool cmp(T b,T c)
{
    if (b.t!=c.t) return (b.t<c.t);
    return (b.d>c.d);
}
void printtree()
{
    cout<<endl;
    for (int i=0; i<2*n+1; ++i)
        cout<<node[i].l<<' '<<node[i].r<<' '<<maxV[i]<<endl;
}

int main()
{
    MAXF=100000;
    MAXF=MAXF*MAXF;
    MAXF+=1000000000;
    cin>>n>>k;
    for (int i=0; i<n; ++i)
        scanf("%lld %lld",&a[i].t,&a[i].d);
    sort(a,a+n,cmp);
    for (int i=0; i<n; ++i)
        ed[a[i].t]=i;
    for (int i=0; i<=k; ++i)
        bg[i+1]=ed[i]+1;
    bg[1]=0;

    cout<<endl;
    for (int i=0; i<n; ++i)
    {
        cout<<a[i].t<<' '<<a[i].d<<endl;
    }
    cout<<endl;
    for (int i=1; i<=k; ++i)
        cout<<bg[i]<<' '<<ed[i]<<endl;

    build(1,0,n-1);
    cout<<endl;
    for (int i=0; i<2*n+1; ++i)
        cout<<node[i].l<<' '<<node[i].r<<' '<<maxV[i]<<endl;
    update(1,0,n-1,0,n-1,1);
    cout<<endl;
    for (int i=0; i<n; ++i)
    {
        int ind;
        cout<<i<<' '<<query(1,0,n-1,i,i,ind)<<' '<<ind<<endl;
    }
    cout<<endl;

    for (int i=1; i<=k; ++i)
    {
        int ind=0;
        ans+=query(1,node[1].l,node[1].r,0,n-1,ind);
        cout<<i<<' '<<ans<<' '<<ind<<endl;
        update(1,0,n-1,ind,ind,-MAXF);
        printtree();
        int indt=a[ind].t;
        if (flag[indt])
        {
        }else
        {
            nowt+=1;
            update(1,0,n-1,0,bg[indt]-1,nowt*2+1);
            update(1,0,n-1,ed[indt]+1,n-1,nowt*2+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
