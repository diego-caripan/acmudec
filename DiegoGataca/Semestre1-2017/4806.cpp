#include <bits/stdc++.h>

using namespace std;


int main(){
  int n,b,aux;
  while(1){
    scanf("%d %d",&n,&b);
    if(n == 0 && b == 0)break;
    vector <bool> estado(n+1,false);
    vector <int> bola;
    for(int i = 0; i < b; i++){
      scanf("%d",&aux);
      bola.push_back(aux);
    }
    for(int i = 0; i < b; i++){
      for(int j = i; j < b; j++) estado[abs(bola[i]-bola[j])] = true;
    }
    bool flag = true;
    for(int i = 0; i < n+1; i++){
      if(!estado[i]){
	flag = false;
      }
    }
    if(flag) puts("Y");
    else puts("N");
  }
  return 0;
}
