#include <stdio.h>
#include <set>
#include <iostream>
#include <cstdio>
using namespace std;
//usa multiteset porque se deben guardar repetidas veces los valores
int main(){

 multiset<long>s
 //iteradores para el multiset
 multiset<long>::iterator sit,rrsit;

 long T,n,cost,tmp;
 // lee la cantidad de casos
 while(scanf("%ld", &T) && T){
  cost = 0;
  while(T--){
    // boletas en el dia
   scanf("%ld",&n);
    // lee las boletas que van al multiset
   while(n--){
    scanf("%ld",&tmp);
    s.insert(tmp);
   }
    // iterador al primer elemento
   sit = s.begin();
   // iterador al ultimo elemento
   rrsit = s.end();
    //disminuye en 1 el ultimo elemento
   --rrsit;
   // almacena la diferancia del ultimo con el primer elemento
   cost += (*(rrsit) - *(sit));
    // elimina los elementos analizados en esa iteracion
   s.erase(sit);
   s.erase(rrsit);

  }
// imprime el costo de la oferta
  printf("%ld\n",cost);
  // limpia el multiset
  s.clear();
 } 
 return 0;
}