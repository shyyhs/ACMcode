#include<iostream>
#include<utility>
#include<string>
#include<tuple>
#include<stdexcept>
#include<map>
using namespace std;

int main()
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

    return 0;

}

