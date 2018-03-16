/*
Comentarios para problema 11489
El truco es contar los numeros%3
Se define e conteo de elementos del arreglo con num%3 == 0 como x
Se define e conteo de elementos del arreglo con num%3 == 1 como y
Se define e conteo de elementos del arreglo con num%3 == 2 como z

Entonces la pregunta se refiere al número restante que debería ser divisible por 3 después
 de eliminar un elemento, que significa que suma%3 == 0.
Entonces, si la suma inicial es %3==0, entonces un número con %3==0 solo se puede eliminar en todos los intentos.
Si la suma inicial es %3==(1 o 2), entonces un número con %3==(1 o 2) respectivamente puede eliminarse
 en el primer intento (si está disponible o S pierde), y luego %3==0 números solo pueden ser eliminado en intentos sucesivos.
Así, la última persona en eliminar un elemento %3==0 gana el juego.

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
// r = 1 => T ganó, r = 0 => S ganó
    int r,n,x,y,z,t,l,tt=1;
    int ans=0;
    string p;

    scanf("%d",&t);
    while(t--){
        printf("Case %d: ",tt++);
        cin >> p;
        x=0;
	y=0;
	z=0;
	ans=0;
        n = p.size();
// Se ve cada elemento del array si es %3 == 0,1 o 2
        for(int i=0; i<p.size(); i++){
            l=p[i]-'0';
            if(l%3==0)
                x++;
            else if(l%3==1)
                y++;
            else
                z++;
            ans=(ans+l)%3;
        }
// Si la suma es %3 == 0
        if(ans==0){
	// Si x%2 == 0 implica que ganó T
            if(x%2==0)
                r=1;
	// Si no, ganó S
            else
                r=0;
        }
// Si la suma es %3 == 1 
        else if(ans==1){
	// Si el largo es 1 gana S
            if(n==1)
                r=0;
	// Si y==0, significa que ganó T
            else if(y==0)
                r=1;
            else{
                if((x+1)%2==0)
                    r=1;
                else
                    r=0;
            }
        }
        else{
            if(n==1)
                r=0;
            else if(z==0)
                r=1;
            else{
                if((x+1)%2==0)
                    r=1;
                else
                    r=0;
            }
        }
        if(r)
            printf("T");
        else
            printf("S");
        printf("\n");
    }

    return 0;
}
