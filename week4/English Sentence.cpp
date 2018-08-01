#if 0
１０分ぐらいかかりました。
mapのことを勉強しました。
#endif
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  string word,frequent,longest;
  size_t N = 0;
  map<string,int> table;
  while(cin >> word){
    table[word]+=1;
    if(table[word] > N){
      N = table[word];
      frequent = word;
	}
    if(word.size() > longest.size()){
      longest = word;
    }
  }
  cout << frequent << " " << longest << endl;
}
