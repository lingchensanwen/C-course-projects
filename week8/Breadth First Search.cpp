#if 0
最初は例題と問題はあまり関係ないと考え、パスしました。
そのあとは例題は後に役に立つに気づいて、最初に戻ってやってみました。
この問題は久し振りに、授業中に完成して、第一回から初めてのことです。
キューについて、そして、幅優先検索も復習しました。
２０分ぐらいかかりました。
c＋＋が完全にわからない自分から、いつもプログラムに弱い自分から、今にやってきて、よかったです。
#endif
#include <queue>
#include <iostream>
using namespace std;
void makev();
void bfs(int src);
int n;
int V[100][100] = {0};
int D[100] = {0};
int i,j,k;
int counter1 = 0;
int main(){
  makev();
  bfs(0);
  cout << 1 << ' ' << 0 <<endl;
  for(int i = 1; i < n; i++)
    if(D[i])
      cout << i+1 << ' ' << D[i] << endl;
    else
      cout << i+1 << ' ' << -1 << endl;
}
void bfs(int src){
  queue<int> Q;
  Q.push(src);
  D[src] = 0;
  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    for(i = 0; i < n; i++)
      if(V[cur][i] == 1 && D[i] == 0){
	D[i] = D[cur] + 1;
        Q.push(i);
      }
  }
}
void makev(){
  cin >> n;
  while(1){
    cin >> i;
    cin >> k;
    int counter2 = 0;
    while(k!=0){
      counter2++;
      cin >> j;
      V[i-1][j-1] = 1;
      if(counter2 == k)
      break;
    }
    counter1++;
    if(counter1 == n)
      break;
  }
}
