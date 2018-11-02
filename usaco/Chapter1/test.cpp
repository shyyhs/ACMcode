#include<iostream>
#include<utility>
#include<string>
#include<tuple>
#include<stdexcept>
#include<map>
#include<algorithm>
using namespace std;

void test_map()
{
    map<char,int> mymap;
    map<char,int>::iterator it;
    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;    
    mymap.insert(pair<char,int>('g',70));
    mymap.erase('a');
    for (it=mymap.begin(); it!=mymap.end(); ++it)
    {
        cout<<it->first<<' '<<it->second<<endl;
    }
}

auto cmp = [](int a, int b){return a<b;};

void test_lambda()
{
    int a[3]={1,2,3};
    sort(a,a+2,cmp);
    for (int i=0; i<3; ++i)
    {
        cout<<a[i]<<endl;
    }
}

int main()
{

    test_lambda();
    return 0;

}

