/*
http://mycodemanual.blogspot.cl/2014/02/uva-11136-hoax-or-what-c-solved-0849s.html

Se guardan los numeros del input en un map, para que esten ordenados, todos los dias
se sacan las mayores y los menores, se disminuyen respectivamente de cada urna, pues 
ya se eligieron, cuando lleguen a ser cero, se eliminan del map, se calcula la resta
para saber cuando deben pagar al final de cada dia (la diferencia de las facturas).
por ultimo, ans tiene todos los pagos que se hacen cada día, entonces, como se va sumando
a si mismo cada vez, al final contiene la cantidad exacta que se pagó en total
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std ;

map < int  ,int > urn ;
map < int ,int > :: iterator it , fit ;
int main(){
  int n , x  ,  i ,  j , k  ,a ,b;
  long long ans ;
  while ( scanf("%d",&n)){
        if ( n == 0)
        break ;
        urn .clear () ;
        ans = 0;
        for ( i = 0 ; i < n ; i++)
        {
                scanf("%d",&k);
                for ( j = 0 ; j < k ; j++){
                     scanf("%d",&x);
                     urn[x]++ ;
                }
          it = urn.begin() ;
          fit = urn.end() ; fit -- ;
         
          a = (*fit).first ; b = (*it).first ;
          ans += a - b ;
          urn[a] -- ; urn[b]--;
          if ( urn[a] == 0)
          urn.erase (fit) ;
          if (urn[b] == 0)
          urn.erase (it);        
        
        }
        printf("%lld\n",ans);       
    }
    return 0 ;
} 