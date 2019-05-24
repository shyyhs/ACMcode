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

struct point
{
    int x,y;
};

struct slope_struct
{
    int y,x;
};

struct pro_struct
{
    double s,e;
};

struct int_p_struct
{
    double x;
    int idx;
    bool flag;
};
int n;

squre s[1100];

point p[4400];
int t=0;

slope_struct slope[16000000];
int st=0;

pro_struct pj[1200];

map <pair <int, int>, bool> mp;
map <pair <int, int>, bool>::iterator it;

int_p_struct int_p[3000];
int ip=0;

int gcd(int x, int y)
{
    if (y==0) return x;
    return gcd(y,x%y);
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
    for (int i=0; i<n; ++i)
        for (int j=0; j<4; ++j)
        {
            p[t].x = s[i].x[j];
            p[t].y = s[i].y[j];
            t++;
        }
}


void get_slope_pairs()
{
    for (int i=0; i<t; ++i)
        for (int j=0; j<t; ++j)
        {
            int x = p[i].x - p[j].x;
            int y = p[i].y - p[j].y;
            if (x==0 && y==0) continue;
            if (x==0) y=1; if (y==0) x=1;
            if (x && y)
            {
                int g = gcd(x,y);
                x/=g;
                y/=g;
            }
            mp[pair<int,int>(y,x)] = 1;
        }
    for (it = mp.begin(); it!=mp.end(); ++it)
    {
        slope[st].y = it->first.first;
        slope[st].x = it->first.second;
        st++;
    }
}

void get_pj(int pj_i, int slope_y, int slope_x)
{
    double min_project = 2000000000;
    double max_project = 2000000000;
    double k = double(slope_y)/slope_x;
    double tmp;  
    for (int i=0; i<4; ++i)
    {
        tmp = s[pj_i].y[i] - k*s[pj_i].x[i];
        min_project = min(min_project, tmp);
        max_project = max(min_project, tmp);
    }
    pj[pj_i].s = min_project;
    pj[pj_i].e = max_project;
}

bool int_p_cmp(int_p_struct a, int_p_struct b)
{
    return a.x < b.x;
}

int cal_slope_from_pj()
{
    ip = 0;
    for (int i=0; i<n; ++i)
    {
        int_p[ip].x = pj[i].s;
        int_p[ip].idx = i;
        int_p[ip].flag = 0;
        ip++;
        int_p[ip].x = pj[i].e;
        int_p[ip].idx = i;
        int_p[ip].flag = 1;
        ip++;
    }
    sort(int_p, int_p+ip, int_p_cmp);
    for (int i=0; i<ip; ++i)
    {
        if (int_p[ip].flag == 0)
            pj[int_p[i].idx].s = i;
        else
            pj[int_p[i].idx].e = i;
    }

}


int cal_slope(int slope_i)
{
    int slope_y = slope[slope_i].y;
    int slope_x = slope[slope_i].x;
    for (int i=0; i<n; ++i)
        get_pj(i, slope_y, slope_x);
    return cal_slope_from_pj();
}

void solve()
{
    get_slope_pairs();
    int ans = 0;
    for (int i=0; i<st; ++i)
        ans = max(ans, cal_slope(i));
    cout << ans << endl;
}

int main(int argc, char*argv[])
{
    init(argv);
    solve();

    return 0;
}
