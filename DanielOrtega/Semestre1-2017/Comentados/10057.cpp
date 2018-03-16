#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
  
const int maxn = 1000005;  
int num[maxn];   
  
  /*
  El problema consiste en encontrar un numero tal que, todos los numeros ingresados, se le puede restar un valor
  y la suma de todos los valores restados sea el minimo 

  se imprimem 3 valores por caso:
  primero se entrega el numero que cumple la propiedad, de que la resta con ese numero sea la minima
  segundo se entrega la cantidad de numeros que satisfacen la propiedad, que estan dentro del input
  (3)tercero se entrega la cantidad de numeros posibles que satisfagan la propiedad
    
  en el fondo el problema consiste en encontrar la mediana, ya que la mediana es el unico numero que cumplira la propiedad,
  se debe notar que (3) puede valer 1 o 2, depediendo si la cantidad de numeros entregados sea par o impar 
    */


int main() {  
    int n; 
    // lee la cantidad de casos 
    while(scanf("%d", &n),n){

        // lee los numeros de casos
        for(int i=0; i<n; i++) {  
            scanf("%d", &num[i]);  
        }  
      // ordena los numeros
        sort(num, num+n);  
        // obtiene la mediana
        int k = (n - 1) / 2;  
        int n1 = 0, n2 = 1;  

        // el numero es impar
        if(n%2 == 1) {  
            for(int i=k; i>=0 && num[k] == num[i]; i--) n1++;  
            for(int i=k+1; i<n && num[k] == num[i]; i++) n1++;  
        }  
        // el numero es par
        else {  
            for(int i=k; i>=0 && num[k] == num[i]; i--) n1++;  
            for(int i=k+1; i<n && num[k+1] == num[i]; i++) n1++;  
            n2 = num[k+1] - num[k] +1;  
        }  
        printf("%d %d %d\n", num[k], n1, n2);  
    }  
    return 0;  
}   