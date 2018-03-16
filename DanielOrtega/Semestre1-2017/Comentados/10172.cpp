/**
Si tienes problemas entendiendole al problema checa este caso:
Entrada:
1
3 2 2 
2 3 3
0
1 2
Salida:
20
**/




#include <cstdio>
#include <queue>
#include <stack>
using namespace std;


/*
    El problema consiste en entregar el tiempo que se demora en total, en repartir, todas las cajas en disitntos nodos dado el input.
    por cada movimiento de caja, se toma en consideracion que avanza el tiempo en 1 minuto y por cada "decargada y cargada" se agregan 2 minutos de penalizacion,
    que corresponde a lo q se demora en dar la vuelta
*/

/*
El problema intenta simular algo asi

de pila c, se llena el nodo1, con la capacidad maxima, si aun quedan elementos, se continua, dandole elementos al nodo2

pila(c) -> nodo1(qc[0]) -> nodo2(qc[1]) -> nodo3(qc[2]) -> ......-> nodon(qc[n-1])
                              <-            <-            .......          <-

como nodo1, ya se lleno, se dara la "vuelta" y corresponde trabajar con el nodo2 y despues avanzar al nodo3
y asi sucesivamente hasta que ya no queden mas nodos, lo que se busca, es saber cuanto se demora en dar la vuelta completa

*/

const int NC = 100;

int main(void){
        // lee el numero de casos
    scanf("%*d");
        /*
        n corresponde a la cantidad de estaciones en el problema
        s capacidad total q se pueden cargar, cantidad maxima de cajas que se puede llevar
        q maximo numero de cargas que pueden quedar en cola
        */
    for(int n, q, s; scanf("%d %d %d", &n, &s, &q) == 3; ){
        /*
        qc cola que tiene la cantidad de "nodos" 
        c pila sirve para 
        */
        queue<int> qc[n];

        stack<int> c;
        for(int i = 0, v, z; i < n; ++i){
            scanf("%d", &z);
            while(z--){
                scanf("%d", &v);
                qc[i].push(--v);
            }
        }
        // at, muestra la especie de nodo, con la que se esta trabajando 
        // minutes, mantiene un registro del tiempo total demorado en repatir todas las cajas
        int at = 0, minutes = 0;
        while(true){
            // Unloading
            // esta parte descarga los elementos que se encuentran en la pila, mientras los elementos descargados de la pila,
            // no supere al maximo de numeros que pueden estar en la cola
            while(!c.empty() && (c.top() == at || qc[at].size() < q)){
                    // agrega elementos en la cola, mientras no sobrepasen al numero correspondiente a esa iteracion
                if(c.top() != at) qc[at].push(c.top());
                // saca elementos de la pila
                c.pop();
                //suma minutos al contador
                ++minutes;
            }
            // Loading
            // carga la mayor cantidad de elementos posibles que se encuentran en la cola a la pila 
            while(c.size() < s && !qc[at].empty()){
                // mete el mayor elementos de la cola a la pila 
                c.push(qc[at].front());
                //elimina el elemento de la 
                qc[at].pop();
                //suma minutos al contador
                ++minutes;
            }
            // revisa, es un booleano que indica si quedan mas elementos o no en la pila
            bool over = c.empty();
                // &= operador a nivel de bits, es una forma abreviada de escribir a = a && b” -> a &= b
            // por lo que en el fondo, esta operacion, verifica que no queden mas elementos en la cola
            for(int i = 0; over && i < n; ++i) over &= qc[i].empty();
            if(over) break;
            // si no termina suma 2 minutos
            minutes += 2;
            // le suma 1 a at, respetando la condicion de q at, no puede ser mayor a n
            at = (at + 1) % n;
        }
        // imprime el valor apra el caso actual
        printf("%d\n", minutes);
    }
}