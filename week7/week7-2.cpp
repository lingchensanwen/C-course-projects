#if 0
１時間半ぐらいかかりました。最初はスライドを見て、pairで解決したいと思ったけど、なかなかうまく行かなかったため、中にはsortの使いは一番迷っかったんだから、たくさんの時間かかちゃいました。そのあとは、諦めて、構造体にしました。そして、ネットでsortをどうやって、三つ変数ある構造体に順番をつくのを調べ、bool cmpを入れることで、解決しました。
そのあとは、配列の大きさは間違ったから、数字が大きかったら、おかしくなってしまうから、ちょっと迷ったこともありますけど、最後問題をよく見直して、解決し、ACできて、よかったです。
以前もグラフについて、アルゴリズムに触ったことがありますけど、ほとんどはc言語でやりました。集合でまた関数で、それを解決することは一番勉強したものだと思います。
#endif
#include <iostream>
#include <algorithm>
using namespace std;
int P[10010]; 
void init(int N) {
for (int i=0; i<=N; ++i) P[i] = i;
}
int root(int a) {
if (P[a] == a) return a;
return (P[a] = root(P[a]));
}
bool is_same_set(int a, int b) { 
return root(a) == root(b);
}
void unite(int a, int b) {
P[root(a)] = root(b);
}
struct pair1{
  int first;
  int second;
  int cost;
};
bool cmp(pair1 p1,pair1 p2){
  return p1.cost<p2.cost;
}
int main(){
    int N;
    int M = 0;
    int A[101][101];
    int cost[10001];
    int src[10001];
    int dst[10001];
  cin >> N;
  for(int i = 0; i < N; i++)
    for(int j =0; j < N; j++)
      cin >> A[i][j];
  for (int r=0; r<N; r++)
    for (int c=r; c<N; c++)
      if (A[r][c] > -1) {
	cost[M] = A[r][c];
	src[M] = r;
	dst[M] = c;
	M += 1;
}
  struct pair1 edges[10000];
  for(int i = 0; i < M; i++){
    edges[i].first = src[i];
    edges[i].second = dst[i];
    edges[i].cost = cost[i];
  }
  sort(edges,edges+M,cmp);
  init(10000);
  long int sum= 0;
  for (int i=0; i<M; ++i) {
      if(is_same_set(edges[i].first,edges[i].second))
          continue;
    unite(edges[i].first,edges[i].second);
    sum = sum + edges[i].cost;
  }
  cout << sum << endl;
}
