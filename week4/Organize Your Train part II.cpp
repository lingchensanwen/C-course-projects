#if 0
時間は三時間か四時間ぐらいかかってしまいました。
最初はちゃんと問題を見ていないためでしたから、なかなかうまくいかなかったです。
そして、ちょっと調べて見ました。
その考えに沿って、コードを完成しました。
ACできて、良かったですね。
今回はset及び集合のメリットを利用しました、それは重ならないことです。
他のはqueueのc＋＋のオプションも少しわかるようになりました。
今でもバグが出てきますけど、以前より直すスピードは早くなることに気づきました。
#endif
#include<set>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

void reverse(string &s){
  char t;
  int len = s.length();
  for(int i = 0; i < len/2 ; i++){
    t = s[i];
    s[i] = s[len-1-i];
    s[len-1-i] = t;
  }
}

int Connect_Possible(string s){
  set <string> S;
  string str1,str2;
  string reconnect_str;
  int len = s.length();
  for(int i = 0; i < len-1;i++){
    str1 = s.substr(0,i+1);
    str2 = s.substr(i+1,len-1-i);
    //あわゆる可能性
    //str1,str2は反転しない
    reconnect_str = str1 + str2;
    S.insert(reconnect_str);
    reconnect_str = str2 + str1;
    S.insert(reconnect_str);
    //str1反転、str2反転しない
    reverse(str1);
    reconnect_str = str1 + str2;
    S.insert(reconnect_str);
    reconnect_str = str2 + str1;
    S.insert(reconnect_str);
    //str1反転、str2反転
    reverse(str2);
    reconnect_str = str1 + str2;
    S.insert(reconnect_str);
    reconnect_str = str2 + str1;
    S.insert(reconnect_str);
    //str1反転しない、str2反転
    reverse(str1);
    reconnect_str = str1 + str2;
    S.insert(reconnect_str);
    reconnect_str = str2 + str1;
    S.insert(reconnect_str);}
  return S.size();
}

int main(){
  int n;
  string s;
  queue <int> Q;
  cin >> n;
  for(int i = 0; i < n ; i++){
    cin >> s;
    Q.push(Connect_Possible(s));}
  for(int i = 0; i < n; i++){
    cout << Q.front() << endl;
    Q.pop();} 
return 0;
}
