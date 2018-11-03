#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
using namespace std;

int main()
{
    double f=123.4567;
    FILE *fp = fopen("text.txt","w");
    fprintf(fp,"%.3f",f);
    return 0;
}
