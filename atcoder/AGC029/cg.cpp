#include<iostream>
#include<ctime>
#include<random>
using namespace std;


int main()
{
    srand(time(NULL));
    int n=1+rand()%100;
    cout<<n<<endl;
    for (int i=0; i<n; ++i)
        cout<<1+rand()%10<<' ';
    cout<<endl;
    return 0;
}
