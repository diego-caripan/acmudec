#include <cstdio>
#include <cstring>

/*
El problema consiste en ver si los inputs dados son o no, substrings de algun otro string dado, los casos terminan, cuando se lee el 9
*/

int main(){

   
   
    char  cds[8][11];
    
    int   i=0, j, num=1, is=1;
    char  *less = NULL;
    char  *greater = NULL;
    
    while (scanf("%s", cds[i]) != EOF)    {
        // si se lee el 9 significa que no quedan mas casos por leer, por lo que se entrega una respuesta
        if (cds[i][0] == '9')        {

            if (is) printf("Set %d is immediately decodable\n", num++);
            else printf("Set %d is not immediately decodable\n", num++);
            i = 0;
            is = 1;
            continue;
        }
        // si is = 1 se sigue resolviendo, en caso de is = 0, ya no hay necesidad de evaluar, 
        //ya que se sabe que uno, ya fue prefijo de uno anterior y ya no es codificable inmmediatamente
        if (is)
            for (j=0; j<i; ++j) {

                greater = cds[i];
                less = cds[j];
                if (strlen(cds[j]) > strlen(cds[i]))   {
                    greater = cds[j];
                    less = cds[i];
                }
                    //compara los substring, por la longitud del elemento mas pequeño, donde strncmp = 0 si ambos elementos son iguales
                    // en la cantidad de caracteres a comparar 
                if (! strncmp(less, greater, strlen(less)))
                    is = 0;
            }
        ++i;
    }
    return 0;
}