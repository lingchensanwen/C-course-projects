#if 0
４時間ぐらいかかりました。
最初は一つの山に力を入れて、頑張りました。
そのあとは二つ以上の山はデータをどうしょりすれば、交点をどう処理すればいいのか悩んでいました。
そのあとは他の人のoneをちょっと参考し、データの構造を配列にしました。
そのあとは色々頑張って、問題12までACされました。
そのあとはタイムオーバーが出てしまいます。しかもテストのデータの中身が見えないため、どうしていいのかわからない状態です。
一応提出して、時間があれば、考えます。
#endif
#include <iostream>
#include <math.h>
#include<algorithm>
#define Inf 10000
using namespace std;
int W,H,N;
double a,p,q;
int xcounter = 0;
int A[105],P[105],Q[105];
double X[10010];//record the x of edge
double f(double x,int i){
  double y = A[i]*(x-P[i])*(x-P[i])+Q[i];//fuction
      return y;
}
double length(double x,int i){
  double y = 2*A[i]*(x-P[i]);//diff
  double sum = sqrt(1+y*y);
  return sum;
}
double squrare(double s, double e, int i){
  double x1 = s*Inf;
  double x2 = x1+1;
  double sum = 0;
  while(x2 < e*Inf ){
    sum = sum + (length(x1/Inf,i) + 4*length((x1+x2)/(2*Inf),i) + length(x2/Inf,i))/(6.0*Inf);
    x1 = x2;
    x2 = x2+1;
  }
  return sum;
}
int main(){
    int flag = 0;
  cin >> W >> H >> N;
    //input a,p,q
  for(int i = 0; i < N;i++){
    double s,e;
    cin >> a >> p >> q;
    A[i] = a;
    P[i] = p;
    Q[i] = q;
  }
    //add special x into X
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            if(i==j)continue;
            int a = A[i]-A[j];
            int b = (-2.0)*(A[i]*P[i]+A[j]*P[j]);
            int c = A[i]*P[i]*P[i] -A[j]*P[j]*P[j]+Q[i]-Q[j];
            if(a!=0){
                double delta = b*b-4*a*c;
                if(delta > 0.0){
                    delta = sqrt(delta);
                    if((-b+delta)/(2.0*a) <=W && (-b+delta)/(2.0*a)>=0)
                        X[xcounter++]=(-b+delta)/(2.0*a);
                    if((-b-delta)/(2.0*a) <=W && (-b-delta)/(2.0*a)>=0)
                        X[xcounter++]=(-b-delta)/(2.0*a);
                }
                else if(delta == 0)
                    X[xcounter++] = -b/(2.0*a);
            }
            if(a == 0)
                X[xcounter++] = (A[i]*(P[i]*P[i]-P[j]*P[j])+Q[i]-Q[j])/(2.0*A[i]*(P[i]-P[j]));
            else if(b!=0)
                    X[xcounter++] = -c/(1.0*b);
        }
        int h = f(0,i);
        double s = 0;
        double e = W;
        if(h<=0){
            s = P[i]-sqrt(-Q[i]/A[i]);//add p-sqrt(-q/a) into x
            if(s>=0)
                X[xcounter++] = s;
        }
        if(s+2*(P[i]-s) <=W ){
            double e = s + 2*(P[i]-s);
            X[xcounter++] = e;
        }
        if(0 <= f(W,i))
            flag = 1;
        
    }
    if(flag == 1)
        X[xcounter++] = W;
    sort(X,X+xcounter+1);
    double sum = 0;
    for(int i = 0; i < xcounter;i++){
        double my = -0.0000001;
        int markj = -1;
        for(int j = 0; j < N; j++){
            double y = f(X[i],j);
            if(my <= y && y<=H){
                my = y;
                markj = j;
            }
        }//find the function highest
        if(markj != -1){
            sum =  sum + squrare(X[i],X[i+1],markj);
        }
    }
    cout<<sum<<endl;
}
