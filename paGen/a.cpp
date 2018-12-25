#include<iostream>
using namespace std;
int y,m,d;
int main()
{
    cin>>y>>m>>d;
    if (m!=12 || d!=25)
    {
        cout<<"NOT CHRISTMAS DAY"<<endl;
        return 0;
    }
    cout<<y-2018<<endl;
    return 0;
}
