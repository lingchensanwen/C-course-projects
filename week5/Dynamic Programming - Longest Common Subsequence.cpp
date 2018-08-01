#if 0
一時半ぐらいかかりました
最初はstring X,Y;なのに、strlen(X),strlen(Y);が使えないのを困りました。
調べた結果、const char* x = X.c_str();を追加することで、使えるようになりました。そして、stringクラスもちょっとわかるようになりました。
c＋＋を全体的な授業を受けることがなくて、今のように少しずつわかってくるのもいいだと思います。
他のはLのi,jのことです。*(x+i-1)==*(y+j-1)は最初−１がないため、なかなかうまくいかなかったけど、最後気づいて、良かったと思います。
#endif
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
    int N;
    int L[1005][1005] = {0};
    cin >> N;
    for(int i = 0; i < N; i++){
        string X,Y;
        cin >> X >> Y;
        const char* x = X.c_str();
        const char* y = Y.c_str();
        for(int i = 0; i < 1000; i++)
            for(int j = 0; j < 1000; j++)
                L[i][j] = 0;
        for(int i = 0; i <= strlen(x); i ++){
            for(int j = 0; j <= strlen(y); j++){
                if(i <= 0 || j <= 0)
                    L[i][j] = 0;
                if(i>0 && j>0){
                    if(*(x+i-1)==*(y+j-1))
                        L[i][j] = L[i-1][j-1] + 1;
                    else
                        if(L[i-1][j] > L[i][j-1])
                            L[i][j] = L[i-1][j];
                        else
                            L[i][j] = L[i][j-1];
                }
            }
        }
        cout << L[strlen(x)][strlen(y)] << endl;
    }
}

