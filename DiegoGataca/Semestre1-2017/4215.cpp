#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int solucion[100];
  solucion[0] = 1;
  solucion[1] = 5;
  for(long long int i = 2; i < 100; i++)solucion[i]=(i+1)*(i+1)+solucion[i-1];
  while(1){
    int n;
    scanf("%d",&n);
    if(n == 0)break;
    printf("%lld\n",solucion[n-1]);
  }
  return 0;
}
