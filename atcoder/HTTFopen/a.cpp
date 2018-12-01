#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
struct Status
{
    int level;
    int train;
}s[11];

struct Mons
{
    int a,b;
    double c;
    int s[11];
} ms[30010];

double nowMoney = 1000;
bool flag[30010];

int t,n,m;
int middle = 700;

void init()
{
    memset(s,0,sizeof(s));
    memset(ms,0,sizeof(s));
    memset(flag,0,sizeof(flag));
    scanf("%d %d %d",&t,&n,&m);
    for (int i=1; i<=m; ++i)
    {
        scanf("%d %d %lf",&ms[i].a,&ms[i].b,&ms[i].c);
        for (int j=1; j<=n; ++j)
            scanf("%d",&ms[i].s[j]);
    }
}

FILE* fin = fopen("a.txt","r");
FILE* fout = fopen("b.txt","w");

void finit()
{
    memset(s,0,sizeof(s));
    memset(ms,0,sizeof(s));
    memset(flag,0,sizeof(flag));
    fscanf(fin,"%d %d %d",&t,&n,&m);
    for (int i=1; i<=m; ++i)
    {
        fscanf(fin,"%d %d %lf",&ms[i].a,&ms[i].b,&ms[i].c);
        for (int j=1; j<=n; ++j)
            fscanf(fin,"%d",&ms[i].s[j]);
    }
}



bool notFull()
{
    for (int i=1; i<=n; ++i)
        if (s[i].level!=10)
            return 1;
    return 0;
} 

double ans2[20];
double pow2(int k)
{
    if (ans2[k]>0.5) return ans2[k];
    ans2[k]=1;
    for (int i=0; i<k; ++i)
        ans2[k]*=2;
    return ans2[k];
}

int minSkill()
{
    int mS = 100;
    int index = -1;
    for (int i=1; i<=10; ++i)
        if (s[i].level<mS)
        {
            mS = s[i].level;
            index = i;
        }
    return index;
}

bool addSkill(int i)
{
    if (s[i].level<10 && nowMoney>10000*pow2(s[i].level+1))
    {
        s[i].train+=1;
        if (s[i].train == (s[i].level+1))
        {
            s[i].level++;
            s[i].train=0;
        }
        nowMoney -= 10000*pow2(s[i].level+1);
        return 1;
    }
    return 0;
}

bool canKill(int i,int turn)
{
    double lowLine = ms[i].a;
    if (lowLine<=middle)
        lowLine+=(ms[i].b-ms[i].a)*(double(turn)/1000);
    else
    {
        lowLine+=(ms[i].b-ms[i].a)*0.99;
    }
    if (!(turn>=lowLine && turn<=ms[i].b && flag[i]==0)) return 0;
    int lackS = 0;
    for (int k=1; k<=n; ++k)
        if (s[k].level<ms[i].s[k])
            return 0;
    return 1;
}

double halfMoney(double money, int lack)
{
    for (int i=0; i<lack; ++i)
        money*=0.5;
    return money;
}

double calMoney(int i,int turn)
{
    double addMoney = ms[i].c;
    addMoney *= (1 + 9 * (double(turn-ms[i].a)/(ms[i].b-ms[i].a)));
    int skillLack = 0;
    for (int j=1; j<=n; ++j)
        skillLack+=max(0,-(s[j].level-ms[i].s[j]));
    if (skillLack==0) addMoney*=10;
    else
    {
        addMoney=halfMoney(addMoney,skillLack);
        addMoney+=1e-9;
    }
    return addMoney;
}

void killMos(int turn)
{
    double msMoney;
    double maxMoney = 999;
    int index=0;

    for (int i=1; i<=m; ++i)
    {
        if (canKill(i,turn))
        {
            msMoney = calMoney(i,turn);
            if (msMoney>maxMoney)
            {
                maxMoney = msMoney;
                index = i;
            }
        }
    }
    if (maxMoney>1000)
    {
        flag[index]=1;
        fprintf(fout,"2 %d\n",index);
        printf("2 %d\n",index);
        nowMoney+=maxMoney;
        return;
    }else
    {
        fprintf(fout,"3\n");
        printf("3\n");
        nowMoney+=1000;
    }
}


void getSkill(int turn)
{
    if (!notFull())
    {
        killMos(turn);
        return;
    }
    int skillIndex = minSkill();
    if (addSkill(skillIndex)==1)
    {
        fprintf(fout,"1 %d\n",skillIndex);
        printf("1 %d\n",skillIndex);
        return;
    }else
    {
        killMos(turn);
        return;
    }
}

void work()
{
    for (int i=1; i<=middle; ++i)
    {
        getSkill(i);
    }
    for (int i=middle+1; i<=1000; ++i)
    {
        killMos(i);
    }
}

void test()
{
    cout<<nowMoney<<endl;
}
int main()
{
    finit();
    work();
    test();
    return 0;
}

