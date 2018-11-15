#include<iostream>
#include<cmath>
using namespace std;
class Complex
{
    public:
    double r,i;
    Complex(double r1,double i1){r=r1,i=i1;}
};

Complex c(2,1);

int main()
{
    cout<<c.r<<endl;
    return 0;
}
