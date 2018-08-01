#include<iostream>
using namespace std;

int E,count=0;

int solve(int E){
  int minimum=0,z_calc;
  for(int z=0; z*z*z<=E;z++){
    if ((z+1)*(z+1)*(z+1)>E){
      z_calc=z*z*z;
      for(int y=0; y*y<=E;y++){
	if ((y+1)*(y+1)+z_calc>E){
	  minimum=z+y+(E-z_calc-y*y);
	  break;
	  break;
	}
      }
    }
  }
  return minimum;
}


int main(){
  while( cin >> E && E>0){
    cout << solve(E) <<endl;
  }
}
