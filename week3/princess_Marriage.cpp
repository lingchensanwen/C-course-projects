#include <algorithm>
#include <iostream>
#if 0
最初は簡単なやつだと思っていました。だが、それを見下してしまいました。
２時間ぐらいかな。
たくさんの時間かかってしまいました。なぜなら、その問題についてはよく見ていなかったからです。
最初書いたやつは自分の考えも間違ったから、どうやっても正しくなれなかったわけですね。
そして、自分は一回計算して、同じ結果を得ることで、プログラミングをもう一度やって見ました。
でも、その後、risk_sumはなにかためずっと０になってしまう状態です。
自分はPDのfirst,secondをたくさんのところに入れ、やって見た結果、その問題を見つけるようになりました。
それはMの値がPD[i].secondより小さい場合は０にしていなかったからです。
そして、もう一個は第一回と似ています。ACしたやつもありますけど、そのあとはぜんぜんだめ。
そして、intをlong intに変えて、ACできました。
入力の計算量：
Nの区間数掛けるN個のPD配列の入力(2*N)で、2*N*Nで、O(2*N*N))です。
全体の計算量：
2*N*N+N*X(X<=N)+N,そして、O(2*N*N)です。
説明：
まずは区間数とお金を入力します。そして、それぞれの区間に対して、道の危険度と長さをPDの配列に入れます。O(2*N*N)
そして、危険度によって、PDの順番を直します。そして、Mと危険度が高いやつの値段（長さ）から比べます。もしMがそれより大きかったら、その道の値段（長さ）を０にします。ここでは、危険度を０にしてもいいけど、ここでは長さを０にします。もし、道の値段が大きいなら、Mを０にして、それに対するMの長さを消します。O(N*X)
最後に危険度の期待値を計算します。O(N)
#endif
using namespace std;
long int N, M;
pair<long int,long int> PD[10010];
int main() {
    while (cin >> N >> M && N) {
        long int d, p;
        long int risk_sum = 0;
        long int count = N-1;
        for (int i=0; i < N; i++) {
            cin >> d >> p;
            PD[i] = make_pair(p, d);
            // PD[i].first は道iの危険度
            // PD[i].second は道iの長さ
        }
        sort(PD,PD+N);
        /*for(int i = 0; i < N; i++)
            cout << PD[i].first <<" "<< PD[i].second <<endl;
         */
        for(long int i = N-1 ; i >= 0;i--)
        while(M > 0){
            if(M > PD[count].second){
                M = M - PD[count].second;
                PD[count].second = 0;
                count--;
            }
            else{
                PD[count].second = PD[count].second - M;
                M = 0;
            }
        }
        for(long int i = 0; i < N ;i++)
            risk_sum += PD[i].first * PD[i].second;
        cout << risk_sum <<endl;
        
}
    return 0;
}
