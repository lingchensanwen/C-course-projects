#if 0
半時間ぐらいかかりました。
c＋＋のキューについて少しわかるようになりました。
最初は問題をよく見ないため、q = 100にして（いつも）、
ちょっと問題が出て、直して、うまくできました。
#endif
#include <queue>
#include <iostream>
/*que struct{
  string name;
  int time;
  }*/
int counter = 0;
using namespace std;
int main(){
  queue<string> Q1;
  queue<int> Q2;
  int n,q;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    string name;
    int time;
    cin >> name;
    cin >> time;
    Q1.push(name);
    Q2.push(time);
  }
  while((!Q1.empty()) && (!Q2.empty())){
    if(Q2.front() <= q){
      cout << Q1.front() <<" ";
      cout << Q2.front() + counter << endl;
      counter = counter + Q2.front(); 
      Q1.pop();
      Q2.pop();
    }
    else{
      Q1.push(Q1.front());
      Q1.pop();
      Q2.push(Q2.front()-q);
      Q2.pop();
      counter = counter + q;
    }
  }
}
