#if 0
20分ぐらいかかりました。
多辺形問題について勉強できて、良かったです。
#endif
#include <complex>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef complex<double> xy_t;
xy_t P[110];

int main(){
  int N = 0;
  double x, y;
  while(scanf("%lf,%lf", &x, &y) != EOF){
    P[N++] = xy_t(x,y);
  }
  //面積計算
  double sum = 0.0;
  for(int i=0; i+2<N; ++i){
    xy_t a=P[0], b=P[i+1], c=P[i+2];
    double a1 =sqrt(pow((c.real()-b.real()),2)+pow((c.imag()-b.imag()),2));
    double b1 =sqrt(pow((c.real()-a.real()),2)+pow((c.imag()-a.imag()),2));
    double c1 =sqrt(pow((a.real()-b.real()),2)+pow((a.imag()-b.imag()),2)); 
    double z=(a1+b1+c1)/2;
    double S=sqrt(z*(z-a1)*(z-b1)*(z-c1)); 
    sum+=S;//三角形abc の面積を合計
  }
  printf("%.6f\n", abs(sum));
}
