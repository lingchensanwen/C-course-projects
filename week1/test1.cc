//minmaxsum.c
#include"stdio.h"
int main(){
  int n, i, min, max;
  long long int sum;
  int a[10000] = {0};
  //printf("Input the number of integer");
  scanf("%d",&n);
  //printf("Input the ai");
  for(i = 0;i < n; i++)
    scanf("%d",&a[i]);
  sum = 0;
  for(min = a[0], max = a[0], i = 0; i < n; i++ ){
    
    if(min > a[i])      
      min = a[i];
    if(max < a[i])
      max = a[i];
      sum += a[i];
    
      }
  printf("%d ",min);
  printf("%d ",max);
  printf("%lld\n",sum);
  return 0;
}
//大きな入力がありうるので,64bit 整数 (long long) を用いる
