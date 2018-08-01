#if 0
一時間ぐらいかかりました。
最初はHとWを逆にして、なかなか結果が出ていない、現在でも、先生の図をあまり見ていないから、先生との座標の表しとは逆ですけど、解けました。
最初はqueue<int,int>をどうやって使うか一応迷った時もありますけど、二つのキューを作ることで解決しました。
そして、無限loopに落ちるのも、HとWが逆のせいです。
またはD[x][y]を−１に設定するところにより、loopや間違う結果も出てきましたけど、
色々バーグを解決して、よかったです。
#endif
#include<cstdio>
#include <queue>
#include <iostream>
using namespace std;
int W,H;
int D[20][20] = {0};
const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
bool valid(int x, int y) {
  if(x < H && x >= 0 && y >= 0 && y < W) 
    return 1;
  else
    return 0;
}
int bfs(int x, int y);
int main(){
  while(1){
  char c;
  int count = 0;
  cin >> W >> H;
  if(W == 0 && H==0)break;
  for(int i = 0; i < H; i++)
    for(int j = 0; j < W; j++){
      c = getchar();
      if(c == '\n') c = getchar();
      if(c == '#')D[i][j] = -1;
      if(c == '@')D[i][j] = 1;
    }
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
	if(D[i][j] == 1)
	  count = bfs(i,j);
    cout << count <<endl;
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
	D[i][j] = 0;
  }
}
int bfs(int x, int y){
  int counter = 1;
  queue<int> Q1;
  queue<int> Q2;
  Q1.push(x);
  Q2.push(y);
  D[x][y] = -1;
  while(!Q1.empty() && !Q2.empty()){
    int x = Q1.front();
    int y = Q2.front();
    Q1.pop();
    Q2.pop();
    for(int i = 0; i < 4; i++)
      if(D[x+dx[i]][y+dy[i]] == 0 && valid(x+dx[i],y+dy[i])){
	counter++;
        Q1.push(x+dx[i]);
	Q2.push(y+dy[i]);
	D[x+dx[i]][y+dy[i]] = -1;
      }
  }
  return counter;
}
