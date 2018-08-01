#if 0
二時間ぐらいかかりました。
いろいろ修正したためです。
最初はi = 0またはj = 0の場合をちゃんと扱っていないため、みんなゼロになってしまいました。
そして、いろいろprintを使って、やっと修正できました。
結果が見えて、うれしかったです。
そして、初期化の位置が間違えたため、セットみんな同じ結果になってしまいました。
今回は漸化式対応のプログラミングが少しわかるようになりました。
#endif
#include <iostream>
using namespace std;
#define tablesize 20
int main(){
    int N;
    int x,y,p;
    int T[tablesize][tablesize];
    int Vert[tablesize][tablesize];
    int Horiz[tablesize][tablesize];
    cin >> N;
    for(int i = 0; i <  N; i++){
        cin >> x >> y >> p;
        for(int i = 0; i < tablesize; i++)
            for(int j = 0; j < tablesize; j++){
                Vert[i][j] = true;
                Horiz[i][j] = true;
            }
        for(int i = 0; i < tablesize ; i++){
            Vert[0][i] = false;
            Horiz[i][0] = false;
        }//初期化
        for(int j = 0; j < p; j++){
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 == x2){
                if(y1>y2)
                    Horiz[x1][y1] = false;
                else
                    Horiz[x1][y2] = false;
            }
            if(y1 == y2){
                if(x1>x2)
                    Vert[x1][y1] = false;
                else
                    Vert[x2][y1] = false;
            }
        }//毎回のマタタビ
        for(int i = 0; i < tablesize; i++)
            for(int j = 0; j < tablesize; j++)
                T[i][j] = 0;
        T[0][0] = 1;
        for(int i = 0; i < tablesize ;i++){
            for(int j = 0; j < tablesize;j++){
                if((Vert[i][j] == false) && (Horiz[i][j] == false) && i && j)
                    T[i][j] = 0;
                if((Vert[i][j] == false) && (Horiz[i][j] == true) && j)
                    T[i][j] = T[i][j-1];
                if((Vert[i][j] == true)&& (Horiz[i][j] == false) && i)
                    T[i][j] = T[i-1][j];
                if((Vert[i][j] == true) && (Horiz[i][j] == true) && i && j)
                    T[i][j] = T[i-1][j] + T[i][j-1];
            }
        }
        if(T[x][y]!=0)
            cout << T[x][y] << endl;
        else
            cout << "Miserable Hokusai!" <<endl;
    }//セット
}
