#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

typedef struct 
{
    int next[300];
    string keyword;
}Node;
Node tree[100000];
int root=1;
int totNodeNumber=1;


int n;


void addToTree(string s)
{
    int now=root;
    for (int i=0; i<s.length(); ++i)
    {
        if (tree[now].next[s[i]]>0)
            now=tree[now].next[s[i]]; //next node exist
        else
        {
            //creat next node
            totNodeNumber++;
            tree[now].next[s[i]]=totNodeNumber;
            now=totNodeNumber;
        }
        if (i==s.length()-1) //reach the last char
            tree[now].keyword=s;
    }
}

void init()
{
    string s;
    cout<<"Please input the number of keywords"<<endl;
    cin>>n;
    cout<<"Please input each keyword in one line"<<endl;
    for (int i=0; i<n; ++i)
    {
        cin>>s;
        addToTree(s);
    }
}

bool findKeyword(string s)
{
    int now=root;
    for (int i=0; i<s.length(); ++i)
    {
        if (tree[now].next[s[i]]==0)
            return 0;
        now=tree[now].next[s[i]];
    }
    if (tree[now].keyword.length()>0)
        return 1;
    else return 0;
}


void work()
{
    string s;
    cout<<"Please input the sentence you want to extract from"<<endl;
    cin>>s;
    int kwNumber=0;
    for (int i=0; i<s.length(); ++i)
        for (int j=i; j<s.length(); ++j)
        {
            string substring;
            substring = s.substr(i,j-i+1);
            if (findKeyword(substring))
            {
                kwNumber++;
                printf("The %dth keyword is ",kwNumber);
                cout<<substring<<endl;

            }
        }
}

int main()
{
    init();
    work();
    return 0;
}
