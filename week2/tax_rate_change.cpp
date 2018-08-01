#include <iostream>
using namespace std;
int main(){
  int x, y, s, max;
  //cout << "Input tax before as x, tax now as y, and the cost as s" << endl;
  //cin >> x >> y >> s;
  int i, j;
do{
  max = 0;
  cout << "Input tax before as x, tax now as y, and the cost as s" << endl;
  cin >> x >> y >> s;
  for(i = 1; i < s; i++)
    for(j = 1; j < s ; j++)
      if( ((i + j) * ( x + 100 ) / 100) == s  )
	if( max < ((i +j) * (y +100 ) / 100)  )
	   max = (i +j) * (y +100 ) / 100;
   cout << max << endl;
 }while(x + y + s != 0);
  return 0;
}

