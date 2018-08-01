#if 0
1時間半ぐらいかかりました。
以前はcの四則運算を書いたことがありましたから、最初問題を見ると今回が早くできるという予感が出てきましたが、pdfを見いている間、前とは違ったことに気づきました。
例題から、書いてみました。以前はスタックでやりました。
今回はこの方法を勉強できて、良かったです。
#endif

#include <iostream>
#include <cassert>
#include <cctype>
using namespace std;
string S;
size_t cur = 0;
int expression();
int parse();
int factor();
char readchar(){
  assert(cur < S.size());
  char ret = S[cur];
  cur +=1;
  return ret;
  //return S[cur++]
}
char peek(){
  assert(cur < S.size());// 1 文字読むがcur を進めない
  return S[cur];
}
int digit(){
  assert(isdigit(peek()));
  int n = readchar() - '0';
  return n;
}

int number(){
  int n = digit();
  while(cur < S.size() && isdigit(peek()))
    n = n * 10 + digit();
  return n;
}
int term(){
  int a = factor();
  while(cur < S.size() && (peek() == '*' || peek() == '/')){
  char op = readchar();
  int b = factor();
  if(op == '*') a*=b;
  else
    a/=b;
}
return a;
}

int expression(){
  int sum = 0;
  sum = term();
  while(peek() == '+' || peek() == '-'){
    char op = readchar();
    int b = term();
    if(op == '+')sum = sum +b;
    else
      sum = sum - b;
    if(cur == S.size())
      break;
  }
  return sum;
}
int parse(){return expression();}
int factor(){
  if(peek() != '(')return number();
  cur += 1;
  int n = expression();
  assert(peek() == ')');
  cur+=1;
  return n;
}
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> S;
  int a = parse();
  cout << a << endl;
  cur = 0;
  }
}
