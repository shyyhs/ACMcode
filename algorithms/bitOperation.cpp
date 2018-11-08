/*
This is about bit operation from basic to advanced.
Ideas from matrix67, code by shyyhs.
 */
#include<iostream>
using namespace std;

//Fast way to calculate gcd when a or b is big number
int stein(int a, int b)
{
    if (a<b) a^=b,b^=a,a^=b;
    if (b==0) return a;
    bool a0=a&0x1,b0=b&0x1;
    if (!a0&&!b0) return stein(a>>1,b>>1)<<1;
    if (!a0&&b0) return stein(a>>1,b);
    if (a0&&!b0) return stein(a,b>>1);
    return stein((a-b)>>1,b);
}
//Part one, the basic part


void partOne()
{
    int a,b;
    a=3,b=2;

    //Check whether a number is odd(num&1==1) or even.
    //&1 means get the last bit of a number in base two.
    cout<<"AND &"<<endl;
    cout<<(a&1)<<' '<<(b&1)<<endl;

    //The operator | may be used for changing a bit into 1
    cout<<"OR |"<<endl;
    cout<<(b|=1)<<endl;
    cout<<(b|=1<<1)<<endl;//will not change since b&(1<<1)==1
    cout<<(b|=1<<2)<<endl;
    //Change a number into the cloeset even number
    cout<<b<<' '<<((b|1)-1)<<endl;
    
    //XOR is for reverse a bit 0^0=0 1^0=1 0^1=1 1^1=1
    cout<<"XOR ^"<<endl;
    a=3,b=2;
    int c=79102371; //c is a random number
    cout<<b<<' '<<(b^1)<<endl;
    cout<<a<<' '<<(a^1)<<endl;
    cout<<a<<' '<<(a^1<<1)<<endl;
    //for any a and c, a^c^c==a
    cout<<(a==(a^c^c))<<endl;
    //swap(a,b) because xor is the reverse function of xor.
    cout<<a<<' '<<b<<endl;
    a=a^b,b=a^b,a=a^b;
    cout<<a<<' '<<b<<endl;

    //NOT is sometimes dangerous because it may affect the sign
    cout<<"NOT ~"<<endl;
    unsigned int d=100;
    cout<<d<<' '<<~d<<endl;
    
    //shl can shift left a number by adding zeros at the end(in base 2)
    cout<<"SHL <<"<<endl;
    for (int i=0; i<=10; ++i)
       cout<<(1<<i)<<' '; 
    cout<<endl;
    cout<<((1<<16)-1)<<endl;
    //shr can be used to substitud for /2
    //print bits of a number from the LSB to MSB(list important bit to most important bit)
    a=1+2+8;
    while(a)
    {
        cout<<(a&1)<<' ';
        a>>=1;
    }
    cout<<endl;



    
}
int main()
{
//    partOne();
    cout<<stein(17*3*2*5,3*2*2*5)<<endl;
    return 0;
}
