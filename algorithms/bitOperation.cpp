/*
This is about bit operation from basic to advanced.
Ideas from matrix67, code by shyyhs.
 */
#include<iostream>
using namespace std;

//gcd(a,b) this is 60% faster than normal gcd(a,b)
//Use this when gcd will be used MANY times and the number is BIG
//Dont use this when you only use gcd for several times because the coding complexity is HIGH
int stein(int a,int b)
{
    if (a<b) a^=b,b^=a,a^=b;
    if (!b) return a;
    bool t1=a&1,t2=b&1;
    if ((!t1)&&(!t2)) return stein(a>>1,b>>1)<<1;
    else if ((!t1)&&(t2)) return stein(a>>1,b);
    else if ((t1)&&(!t2)) return stein(a,b>>1);
    return stein((a-b)>>1,b);
}
//Check there's even 1 or odd 1 in a number(in base 2)
bool odd1(int x)
{
    x^=(x>>1);
    x^=(x>>2);
    x^=(x>>4);
    x^=(x>>8);
    x^=(x>>16);
    return (x&1);
}
//abs
int abs2(int x)
{
    return (~x+1);
}
//Check the number of 1s in a number
int number1s(int x)
{
    x=(x&0x55555555)+((x>>1)&0x55555555);
    x=(x&0x33333333)+((x>>2)&0x33333333);
    x=(x&0x0F0F0F0F)+((x>>4)&0x0F0F0F0F);
    x=(x&0x00FF00FF)+((x>>8)&0x00FF00FF);
    x=(x&0x0000FFFF)+((x>>16)&0x0000FFFF);
    return x;
}
//0s in front
int nlz(int x)
{
    int n=1;
    if (!x) return 32;
    if (!(x>>16)) {n+=16; x<<=16;}
    if (!(x>>24)) {n+=8; x<<=8;}
    if (!(x>>28)) {n+=4; x<<=4;}
    if (!(x>>30)) {n+=2; x<<=2;}
    n-=(x>>31);
}
//Part one, the basic part
void partOne()
{
    //This is the basic part of usage of & | ~ ^ (and or not xor)
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
    while(a)
    {
        cout<<(a&1)<<' ';
        a>>=1;
    }
    cout<<endl;
    int k=3;
    a=10,b=7;
    //Some code without commends
    cout<<(a>>1)<<endl;
    cout<<(a<<1)<<endl;
    cout<<((a<<1)|1)<<endl;
    cout<<(a|1)<<endl;
    cout<<((a|1)+1)<<endl;
    cout<<(a^1)<<endl;
    cout<<(a|(1<<(k-1)))<<endl;
    cout<<(a&(~(1<<(k-1))))<<endl;
    cout<<(a^(1<<(k-1)))<<endl;
    cout<<(a&((1<<(2))-1))<<endl;
    cout<<(a&((1<<(k-1))))<<endl;
    cout<<(a|((1<<k)-1))<<endl;
    cout<<(a^((1<<k)-1))<<endl;
    cout<<(a&(a+1))<<endl;
    cout<<(a|(a+1))<<endl;
    cout<<(a|(a-1))<<endl;
    cout<<((a^(a+1))>>1)<<endl;
    cout<<(a&(a^(a-1)))<<endl;

}
int main()
{
    cout<<abs2(8)<<endl;
//    partOne();
    //    cout<<stein(2*2*3*5,2*5);
    return 0;
}
