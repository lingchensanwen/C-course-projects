#include <iostream>
#include <bitset>
#include <stdio.h>
#include <math.h>
using namespace std;
union double_long_long {
double floating_value;
unsigned long long integer_value;
};
void show_double(double v) {
  double_long_long u;
  u.floating_value = v;
  cout << v << " = " << bitset<64>(u.integer_value) << endl;
  long long sign = u.integer_value >> 63;
  long long exponent = (u.integer_value >> 52)& ((1<<11)-1);
  long long mantissa = u.integer_value & ((1ul<<52)-1);
  cout << " sign = " << sign << endl;
  cout<< " exponent = " << exponent << ' ' << bitset<11>(exponent) << endl;
  cout<< " mantissa = " << mantissa <<' '<<bitset<52>(mantissa) << endl;
  cout << " => " << (sign ? "-" : "+")
       << " (1+" << (double)mantissa/(1ul<<52)
       << ") * " << "2ˆ(" << (exponent-1023) << ")" << endl;
    }
int main() {
    double a = 1000.0;
    show_double(1.0);
    cout << "0.001 is "<<endl;
    show_double(0.001);
    //show_double(1/a);
    //cout << "1/a is "<<endl;
    show_double((1/a)+1);
    show_double(0.001+1-1);
    printf("Now show\n");
    printf("1.0 is %.16f\n",1.0+0.001);
    printf("0.001 is %.32f\n",0.001);
    printf("%.32f\n",(1/a+1));
    printf("%.16f\n",(0.001+1-1));
    printf("%.16f\n",(1/a+1-1)*a);
    printf("7 is %.16f\n",(1/pow(a,7)+1-1)*pow(a,7));
    printf("%.32f\n",(1/pow(a,5)+1-1));
    printf("5+1 is %.32f\n",1/pow(a,5)+1);
    printf("6 is %.64f\n",1/pow(a,6));
    printf("6+1 is %.64f\n",(1/pow(a,6)+1));
    show_double(1/pow(a,6));
    printf("6 in 16 is %.64f\n",(1/pow(a,6) + 1 - 1) * pow(a,6));
    //printf("%.16f\n",0.001*1000);
    // show_double(1/a+1);
  //show_double(1+1/1000.0);
    show_double((1/a+1-1)*a);
    show_double((1/pow(a,5)+1-1)*pow(a,5));
    a = 1024.0;
    show_double(1/pow(a,5));
    show_double(1/pow(a,6));
    printf("A as %.16f\n",(1/pow(a,4)+1-1)*pow(a,4));
    printf("B as %.16f\n",(1/pow(a,6)+1-1)*pow(a,6));
    show_double(1000);
    show_double(100);
    show_double(10);
    show_double(0.001);
    show_double(1/1024.0);
    show_double(1024);
}
