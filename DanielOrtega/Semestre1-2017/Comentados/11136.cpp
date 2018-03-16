#include <cstdio>
#include <set>
#include <iostream>

using namespace std;


/*
El problema consiste en encontrar el menor y el mayor dado un input, los datos son guardados en un multiset, ya que se pueden repetir
los elementos
*/


int main(){

 multiset<long>s
 //iteradores para el multiset
 multiset<long>::iterator sit,rrsit;

 long T,n,cost,tmp;
 // lee la cantidad de casos(dias)
 while(scanf("%ld", &T) && T){
  cost = 0;
  while(T--){
    // lee la cantidad de boletas ingresadas (por dia)
   scanf("%ld",&n);
    // lee los numeros de boletas ingresadas, las cuales son ingresadas en el multiset
   while(n--){
    scanf("%ld",&tmp);
    s.insert(tmp);
   }
    // obtiene el primer elemento que corresponde al mas
   sit = s.begin();
   // obtiene el ultimo elemento que corresponde al mas
   rrsit = s.end();
    //disminuye en 1 el ultimo elemento
   --rrsit;
   // como son iteradores, necesito desreferenciarlo
   // cost, almacena la diferencia entre el mayor y el menor, que corresponde al costo de la promocion
   cost += (*(rrsit) - *(sit));
    // elimina los elementos analizados en esa iteracion
   s.erase(sit);
   s.erase(rrsit);

   // como las operaciones, se van haciendo "todos los dias", por cada iteracion se elimina el mayor y el menor
  }
    // imprime el costo para esa promocion 
  printf("%ld\n",cost);
  // limpia el multiset
  s.clear();
 } 
 return 0;
}