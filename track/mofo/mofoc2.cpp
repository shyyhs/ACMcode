#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

struct squre 
{
    int x[4],y[4];
};

struct slope_struct
{
    int y,x;
    double k;
    slope_struct(int py=0, int px=0)
    {
        y = py, x = px;
        k = atan2(double(py), double (px));
        if (k<0) k = 2*M_PI + k;
    }
    bool operator< (const slope_struct &a) const
    {
        return (this->k < a.k);
    }
    bool operator> (const slope_struct &a) const
    {
        return (this->k > a.k);
    }
    bool operator==(const slope_struct &a) const
    {
        return (abs(this->k - a.k)<1e-7);
    }
    void print()
    {
        cout<<k<<endl;
    }
};

struct int_p_struct
{
    slope_struct sp;
    int sp_rank;
    int idx;
    bool flag;
    bool s_flag;
};

int n;
squre s[1100];

int st;
int_p_struct int_p[4100];

int c[4100];


int lowbit(int x)
{
    return (x&(-x));
}


void insert_point(int p, int num)
{
    while (p<2*n+10)
    {
        c[p]+=num;
        p+=lowbit(p);
    }
}


void insert(int l, int r)
{
    insert_point(l,1);
    insert_point(r+1,-1);
}


int get(int loc)
{
    int ans = 0;
    while (loc)
    {
        ans += c[loc];
        loc-=lowbit(loc);
    }
    return ans;
}


bool cmp1(int_p_struct a, int_p_struct b)
{
    return a.sp < b.sp;
}

bool cmp2(int_p_struct a, int_p_struct b)
{
    if (a.idx!=b.idx)
        return a.idx < b.idx;
    return (a.flag < b.flag);
}

int cal(int sq_num, int p_num)
{
    st = 0;
    memset(int_p,0,sizeof(int_p));
    memset(c,0,sizeof(c));

    slope_struct mink(0,1);
    int_p[st].sp = mink;
    int_p[st].sp_rank = 0;
    int_p[st].idx = -1;
    int_p[st].flag = 0;
    st++;

    slope_struct maxk(-1,200000);
    int_p[st].sp = mink;
    int_p[st].sp_rank = 0;
    int_p[st].idx = -1;
    int_p[st].flag = 0;
    st++;

    int ans = 0;

    int nowx = s[sq_num].x[p_num];
    int nowy = s[sq_num].y[p_num];

    for (int i=0; i<n; ++i)
        if (i != sq_num)
        {
            slope_struct maxk(0,1), mink(-1,200000);
            for (int j=0; j<4; ++j)
            {
                slope_struct tmp(s[i].y[j]-nowy, s[i].x[j]-nowx);
                if (tmp<mink) mink = tmp;
                if (tmp>maxk) maxk = tmp;
            }
            int_p[st].sp = mink;
            int_p[st].sp_rank = 0;
            int_p[st].idx = i;
            int_p[st].flag = 0;
            if (maxk.k - mink.k > M_PI)
                int_p[st].s_flag = 1;
            st++;

            int_p[st].sp = maxk;
            int_p[st].sp_rank = 0;
            int_p[st].idx = i;
            int_p[st].flag = 1;
            if (maxk.k - mink.k > M_PI)
                int_p[st].s_flag = 1;
            st++;

        }
    sort(int_p, int_p+st, cmp1);

    for (int i=0; i<st; ++i)
    {
        int_p[i].sp_rank = i+1;
        if (i>0 && int_p[i].sp == int_p[i-1].sp)
            int_p[i].sp_rank = int_p[i-1].sp_rank;
    }

    sort(int_p, int_p+st, cmp2);
    for (int i=0; i<st; ++i)
    {
        if (int_p[i].idx<0) continue;
        if ((int_p[i].idx == int_p[i+1].idx) && (int_p[i].flag==0))
        {
            if (int_p[i].s_flag!=1)
                insert(int_p[i].sp_rank, int_p[i+1].sp_rank);
            else
            {
                insert(1,int_p[i].sp_rank);
                insert(int_p[i+1].sp_rank, st);
            }
        }
    }
    for (int i=0; i<2*n+10; ++i)
        ans = max(ans, get(i));
    return ans;
}


void solve()
{
    int ans = 0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<4; ++j)
            ans = max(ans, cal(i,j));

    cout << ans+1 << endl;
}


void init(char *argv[])
{
    int w,h;
    freopen(argv[1], "r", stdin);
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cin >> s[i].x[0] >> s[i].y[0];
        cin >> w >> h;
        s[i].x[1] = s[i].x[0] + w, s[i].y[1] = s[i].y[0];
        s[i].x[2] = s[i].x[0], s[i].y[2] = s[i].y[0] + h;
        s[i].x[3] = s[i].x[0] + w, s[i].y[3] = s[i].y[0] + h;
    }
}


int main(int argc, char*argv[])
{
    init(argv);
    solve();

    return 0;
}
