//Sacado de https://github.com/matheussampaio/problems-solving/blob/83e69cd15ffc1ebfb024420a60e50cc5501370e5/UVa/750%20-%208%20Queens%20Chess%20Problem.cpp
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int x,y;    //posición en el tablero de la reina que nosotros posicionamos.
int d;      //número de datasets

int solucion[9];    //arreglo para almacenar solucion
int num;            //numero de soluciones encontradas

void initSolucion(){        //inicializacion del arreglo solucion
    for(int i=0;i<9;i++){
        solucion[i]=0;
    }
}

bool chequeoPosicion(int n_reina, int row) {    //Función para buscar en que posición colocar a la reina
    for (int prev = 1; prev <= n_reina - 1; prev++) {
        if (solucion[prev] == row || (abs(solucion[prev] - row) == abs(prev - n_reina))) {  //La 1ra condición verifica si hay otra reina en la misma fila, la 2da condición verifica si hay otra reina en diagonal. 
            return false; //... de cumplirse alguna de las condiciones, entonces la posición no es válida.
        }
    }
    return true; //si no hay problemas, retorna true.
}

void ponerReina(int n_reina){
    for(int row=1;row<=8;row++){ //revisa en cada fila.
        if(chequeoPosicion(n_reina,row)==true){ //si la reina puede colocarse
            solucion[n_reina] = row;  // se coloca la reina en su posición
            if (n_reina == 8 && solucion[y] == x) { //si hemos llegado a la 8va reina y la reina que hemos ubicado está en su lugar
                printf("%2d      %d", ++num, solucion[1]); //imprime la solución
                for (int j = 2; j <= 8; j++){
                    printf(" %d", solucion[j]);
                }
                printf("\n");
            } else {
                ponerReina(n_reina + 1); //de no haber llegado a la ultima reina aún, se pasa a ubicar a la siguiente reina
            }
        }    
    }
}



int main(){
    cin >> d;
    while(d--){
        cin >> x >> y;
        solucion[y] = x;
        initSolucion();
        num=0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        ponerReina(1);
        if (d) {
            printf("\n");
        }    
    }
    return 0;
}
