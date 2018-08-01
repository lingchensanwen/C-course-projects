#if 0
20分かかりました。木について復習しました。
最初は何を出力すればいいか迷ったことがあります。
そのあとはすらすら解決できて、よかったです。
#endif 0
#include <iostream>
using namespace std;
int P[10010];
void init(int N) {
for (int i=0; i<=N; ++i) P[i] = i;
}
int root(int a) {
if (P[a] == a) return a;
return (P[a] = root(P[a]));
}
bool is_same_set(int a, int b) {
return root(a) == root(b);
}
void unite(int a, int b) {
P[root(a)] = root(b);
}
int main() {
  int n, q;
  int oper;
  int a,b;
  cin >> n >> q;
  init(n);
  for(int i = 0; i < q; i++){
    cin >> oper;
    cin >> a >> b;
    if(oper == 0)unite(a,b);
    if(oper == 1)cout << is_same_set(a,b) << endl;
  }
}
