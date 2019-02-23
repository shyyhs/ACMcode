#include<iostream>
using namespace std;
// f[qi]: whether qi is accepte state
// trans[qi][alphabet]==qj: qi meets some char in alphabet changes to qj
bool f[3]; //f[2] is the unreachable state f[3]==0
int trans[2][2];
int startState=0;

//char accString[4][10] ={"abb","abba","abbba","abbbb"}; this case for test
//char rejString[2][10] = {"",""};

char accString[4][10] ={"abb","abba","abbba","abbbb"};
char rejString[2][10] = {"aba","abbb"};


void printState()
{
    //If find one possible table, print the table out
    printf("\tF\ta\tb\n");
    printf("q0\t%d\t%d\t%d\n",f[0],trans[0][0],trans[0][1]);
    printf("q1\t%d\t%d\t%d\n",f[1],trans[1][0],trans[1][1]);
}

int finalState(char* s)
{
    int now=startState;
    for (int i=0; i<strlen(s); ++i)
    {
        now=trans[now][s[i]-'a'];
        if (now==2) return 2;
    }
    return now;
}

bool checkTable()
{
    for (int i=0; i<4; ++i)
        if (f[finalState(accString[i])]!=1) return 0;
    for (int i=0; i<2; ++i)
        if (f[finalState(rejString[i])]==1) return 0;
    return 1;
}

void stateGene()
{
    //Generate all possible tables
    bool flag=0; //Is there some answer.
    for (int state=0;state<2*2*3*3*3*3; ++state)
    {
        int i=state;
        for (int j=0; j<2; ++j)
            f[j]=i%2,i/=2;
        for (int j=0; j<2; ++j)
            for (int k=0; k<2; ++k)
                trans[j][k]=i%3,i/=3;
        if (checkTable()==true) 
            flag=1,printState();
    }
    if (!flag) cout<<"There is no such FSA"<<endl;
}


int main()
{
    stateGene();
    return 0;
}
