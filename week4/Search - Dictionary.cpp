#if 0
２０分ぐらいかかりました。
setのこととオプションを勉強しました。
#endif
#include <set>
#include <string>
#include <iostream>
using namespace std;
int main(){
  typedef set<string> set_t;
  set_t D;
  int n;
  string cmd;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> cmd;
    if(cmd == "insert"){
      string word;
      cin >> word;
      D.insert(word);
    }
    else if(cmd == "find"){
      string word;
      cin >> word;
      if(D.count(word)!= 0)
	cout << "yes" << endl;
      else if(D.count(word) == 0)
	cout << "no" << endl;
    }
  }
}
