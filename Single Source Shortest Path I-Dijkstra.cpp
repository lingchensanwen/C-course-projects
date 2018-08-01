#if 0
例題30までACできました。
4時間ぐらいかかりました。頑張りました。
残念ながら、タイムオーバーか、幾つのところを変えてみたがTime Limit Exceeded
が解消できず、最後まではACされていませんでした。
一応提出しました。Dijkstra法について復習しました。
そしてpairについて復習しました。
またはpriority_queueにも勉強しました。
#endif
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int V, E, R, S[500010], T[500010], D[500010]; // 問題で与えられる入力
int C[100010]; // 各頂点までの最短距離の上限
int U[100010];//最短距離確定な頂点集合
int Q = 0;//最短距離まだ確定でない頂点集合
// 無限を表す定数を全頂点をたどる最大超に設定
const int Inf = 10000*100000+100;
struct cmp
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.first > b.first;
        }
};
priority_queue< pair<int,int>, vector<pair<int,int> >, cmp > P;//value,point
int main() {
  pair<int,int> p;
  cin >> V >> E >> R;
  for (int i=0; i<E; ++i)
    cin >> S[i] >> T[i] >> D[i]; // 各辺を入力
  for (int i=0; i<V;i++){
    if(i == R){
      C[i] = 0;
    }
    else{
      C[i] = Inf;
      Q++;
      U[i] = 0;
    }
    U[i] = 0;
  }
  p.first = 0;
  p.second = R;
  P.push(p);//
  while(Q&&E) { //Q not empty
      p = P.top();
      P.pop();
      int vn = p.second;//最小距离的顶点在P中
      int counter = 1;
      while(U[vn] == 1 && !P.empty()){
	  //もしvnが決めたら
	   p = P.top();//新しい点をもらう
	   P.pop();//ポップする
	   vn = p.second;
	   counter++;
	   if(counter > 100000)break;
	}
      U[vn] = 1;//vnを1にする
      Q--;//誰でも良い、Qが引ければいい
      for (int i=0; i<E; ++i) 
	if(S[i] == vn){
	  int s = S[i], t = T[i], d = D[i];
	  if(C[s] < Inf && C[t] > C[s] +d)
	    C[t] = C[s] + d;
	  p.first = C[t];
	  p.second = t;
	  P.push(p);
	}
  }
  for (int i = 0; i<V;i++){
    if(C[i] != Inf)
      cout << C[i] << endl;
    else
      cout << "INF" <<endl;
  }// 出力
}
