#if 0
半時間ぐらいかかりました。
最初は-の時、n1-n2にして、ちょっと困った時もありました。
c++のstack　少しわかるようになりました。
#endif
#include <string>
#include <stack>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
  string word;
  stack<int> S;
  while (cin >> word){
    if(word == "+"){
      int n1 = S.top();
      S.pop();
      int n2 = S.top();
      S.pop();
      S.push(n1+n2);
    }
    else if(word == "-"){
      int n1 = S.top();
      S.pop();
      int n2 = S.top();
      S.pop();
      S.push(n2-n1);
    }
   else if(word == "*"){
      int n1 = S.top();
      S.pop();
      int n2 = S.top();
      S.pop();
      S.push(n1*n2);
    }
   else{
     S.push(atoi(word.c_str()));
   }
  }
  cout << S.top() << endl;
}
