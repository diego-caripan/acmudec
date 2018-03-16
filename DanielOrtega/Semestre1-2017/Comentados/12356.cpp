/*
http://www.thebettersd.com/?p=92
*/


#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    unsigned int s, b, l, r;
	
 /* 

 ocupa 2 vectores para almacenar los soldados, uno para los soldados a la derecha y otro para los soldados que estan en la izquierda

 */
    vector<int> left(110000), right(110000);
 
    while (scanf("%d %d", &s, &b), (s || b)) {

        /* incializa los vectores datos, con s, donde s es la cantidad de soldaditos

    donde los vectores se inicializan de la siguiente forma:

    posicion   0 1 2 3 4 5 6 7 
    left      -1 0 1 2 3 4 5 6.....
    right      2 3 4 5 6 7 8 9.....

        */        
        for (int i = 0; i <= s; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        
        while (b--) {
        /*
        se lee la cantidad de reportes de muerte b.

        por cada reporte se leen 2 numeros l y r
        donde se imprimen los sgts caracteres dependiendo del resultado:
        *   imprimir si no quedan soldados en esa linea
        nro indicando los restantes
        -   por cada caso de nuevo
        
        ahora los casos a considerar corresponde a cuando:

        a) si left(l) es menor a 1 se imprime un *, esto significa que ya no quedan mas soladados en esa posicion
        b) en el caso contrario, se imprimira el valor correspodiente a esa posicion. 
        
        c)  si right(r) es mayor a s se imprime un *, esto significa que ya no quedan mas soladados en esa posicion
        d) en caso contrario se imprimira un el valor correspodiente a esa posicion

        luego se proceden a actualizar las posiciones

            donde en left[right[r]] es la ultima posicion donde hay un soldado (este puede estar vivo o muerto), a esa pocicion,
            se le asigna left[l], que corresponden a la cantidad de soldados vivos en ese momento.


            donde en right[left[l]] es la ultima posicion donde hay un soldado (este puede estar vivo o muerto), a esa pocicion,
            se le asigna right[r], que corresponden a la cantidad de soldados vivos en ese momento,      

            
            aqui, se debe notar que en algun momento, en alguna posicion se tendra que para
            left[x] valdra -1 en algun momento, y esto indicara que no quedan soldados en ese vector.
            right[x] valdra un nro mayor a s en algun momento, y esto indicara, que ya no quedan soldados en ese vector.

         */        
            scanf("%d %d", &l, &r);
            if (left[l] < 1) printf("* ");
            else printf("%d ", left[l]);
            if (right[r] > s) printf("*\n");
            else printf("%d\n", right[r]);
            
            left[right[r]] = left[l];
            right[left[l]] = right[r];
        }
        // se imprime el guion, indicando el inicio de un caso nuevo
        printf("-\n");
    }
    return 0;
}