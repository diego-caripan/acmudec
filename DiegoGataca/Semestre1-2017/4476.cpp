#include <bits/stdc++.h>

using namespace std;

long long transformar(long long a){
  long long  retorno = 0,aux = 0;
  retorno = 100;
  aux += 100*2;
  if(aux > a){
    retorno -= ( (aux -a)/2 );
    return retorno;
  }
  else {
    retorno = 10000;
    aux += (10000-100)*3;
    if(aux > a){
      retorno -= ( (aux -a)/3 );
      return retorno;
    }
    else {
      retorno = 1000000;
      aux+= (1000000-10000)*5;
      if(aux > a){
	retorno -= ( (aux-a)/5 );
	return retorno;
      }
      else {
	retorno += ( abs(a-aux)/7 );
	return retorno;	
      }
    }
  }
}


long long dinero(long long w){
  long long retorno = 0;
  if(w >= 100){
    retorno += 100*2;
    w -= 100;
  }
  else{
    retorno += w*2;
    w = 0;
  }
  if(w >= 10000 - 100){
    retorno += (10000 - 100)*3;
    w -= (10000 - 100);
  }
  else{
    retorno += w*3;
    w = 0;
  }
  if(w >= 1000000-10000){
    retorno += (1000000-10000)*5;
    w -=(1000000-10000);
  }
  else {
    retorno += w*5;
    w = 0;
  }
  if(w > 0)retorno += w*7;
  return retorno;
}

long long binaria(long long l , long long r, long long comp){
  long long total = r;
  long long low = l,high = r/2;
  while (low < high) {
    int m = (low+high)/2;
    if(abs(dinero(m)-dinero(total -m)) == comp)return m;
    if (abs(dinero(m)-dinero(total -m)) > comp )
      low = m+1;
    else
      high = m;
  }
  return -1;  
  
}

int main(){
  long long a,b,w,aux;
  while(1){
    scanf("%llu %llu",&a,&b);
    if(a == b && b == 0)break;
    w = transformar(a);
    long long solucion = binaria(0,w,b);
    if(solucion == -1)printf("%llu\n",dinero(w/2));
    else {
      solucion = (solucion < w-solucion)? solucion: w-solucion ;
      printf("%llu\n",dinero(solucion));
    }
  }
  return 0;
}
