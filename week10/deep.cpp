#if 0
３時間ぐらいかかりました
基本的な考えには1時間ぐらいですけど、ディバッグがたくさんの時間かかりました。
一番問題あるのはforの中のifの処理ところでした。
それと図の循環が出ると、時間の判断のところです。
深さ優先探索について復習し、キューについて復習しました。
以前もcで深さ優先について書いたことがありましたが、毎度毎度かく時新しい知識が身につけて、よかったです。
#endif
#include <iostream>
#include <queue>
using namespace std;
int D[105] = {0};
int V[105];
queue<int> Q[105];
int Ntime=0;
int n,u,k,v;
int d[105] = {0};//start time
int f[105] = {0};//end time
void dfs(int cur) { // curを訪問
  // cur の訪問時刻を記録
  Ntime += 1;
  // 動作確認用表示
  //cerr << "visiting " << cur << ' ' << Ntime << endl;
  if(D[cur] == 0)
      d[cur] = Ntime;

  for(int dst = 1; dst <= n; dst++) { // 全ての節点 dst について
    if (D[cur] == 0&&Q[cur].size()>0 && Q[cur].front() == dst && D[dst] == 0) { // curからdstに辺があり,dstを未訪問なら
      if(dst != cur && d[dst] == 0)
          dfs(dst);
      Q[cur].pop();
	}
      if(D[cur] == 0&&Q[cur].size()>0 && Q[cur].front() == dst && D[dst] == 1)
          Q[cur].pop();
  }
  // cur の訪問終了時刻を記録
      Ntime += 1;
    if(D[cur] == 0){
        f[cur] =  Ntime;
        D[cur] = 1;}
  // 関数の終わりで親に戻る (青矢印)
}
int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> u >> k;
    V[i] = i;
    for(int j = 1; j <= k; j++){
      cin >> v;
      Q[u].push(v);     
    }
  }

  for(int i = 1; i <= n; i++)
    if(D[i] == 0)
        dfs(V[i]);
  for(int i = 1; i <= n; i++){
    cout << V[i] <<" "<< d[i] <<" "<< f[i] <<endl; 
  }


}
