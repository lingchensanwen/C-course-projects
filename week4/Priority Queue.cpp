#if 0
半時間ぐらいでした。
最初はbinary heapが必要だと思って、考えました。
便利な順番があるキューが使えて、良かったと思います。
優先度ありのキューを勉強しました。
#endif
#include <queue>
#include <string>
#include <iostream>
using namespace std;
int main(){
  string cmd;
  priority_queue<int> Q;
  while(cin >> cmd && cmd != "end"){
    if(cmd == "insert"){
      int k;
      cin >> k;
      Q.push(k);
    }else if(cmd == "extract"){
      int n = Q.top();
      Q.pop();
      cout << n << endl;
    }
  }
}
