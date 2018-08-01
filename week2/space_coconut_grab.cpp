#if 0
４０分ぐらいかかりました。時間の複雑度についての計算は復習しました。
そして、最初はcountsをcountの名前にして、なかなか出てこないです。
X-codeでやってみて、多分countがfunction名前と同じのが原因だと思っています。
yzの場合は
E = 100counts = 55
E = 10000counts = 2222
E = 1000000counts = 100100
です。
xyの場合は
E = 100counts = 1111
E = 10000counts = 1010101
E = 50000counts = 11200224
です。
xzの場合は
E = 100counts = 505
E = 10000counts = 220022
E = 50000counts = 1850037
です。
Eが増えるとともにcountsはもちろんもっと多い時間がかかっていて、そして、yzの場合はxzよりいい、xzの場合はxyよりいいことがわかってきました。そして、グラフと比べて、そのEのcountsは対応していることもわかります。そして、それぞれの3点を基準として、直線を書いてみたら、やはりグラフと似ている結果がわかってきます。つまり傾斜度はyzは最小で、そしてxz,xyです。
    それはわかりやすいです。
　　計算量はyz:pow(E,1/3)*pow(E,1/2)
          xz:pow(E,1)*pow(E,1/3)
          xy:pow(E,1)*pow(E,1/2)からです。
#endif
#include <iostream>
#include <math.h>
int counts = 0;
using namespace std;
int x,y,z,E;
int solve(int E){
  int ans = 3*E;
  for(y = 0; y <=pow(E,1/2.0); y++)
    for(z = 0; z <= pow(E,1/3.0); z++){
     x = E - y*y -z*z*z;
     // counts++;
     if((ans > x + y + z)&& (x + y*y + z*z*z == E)&& (x >= 0))
	ans = x + y + z;
    }
  return ans;
}

int main(){
  cout << "Input the sum as E:" << endl;
  //int E[3] = {100,10000,1000000};
  while(cin >> E && E > 0){
    cout << solve(E) << endl;
  }
  /*for(int i = 0; i < 3;i++){
      counts = 0;
      solve(E[i]);
      cout << "E = " << E[i] << "count = " << counts << endl;
      }*/
  return 0;
}
