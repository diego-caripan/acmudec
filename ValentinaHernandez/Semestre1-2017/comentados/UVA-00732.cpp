/*Comentado
sacado de:
https://saicheems.wordpress.com/2013/08/26/uva-732-anagrams-by-stack/
*/

#include <cstdio>
#include <iostream>
 
using namespace std;
 
string in, out;
 
/*
Al llamar la prima vez a dfs:
a es el string leido a manipular;
b, stack y path con el string nulo -> "";
n = 0;
*/

void dfs(string a, string b, string stack, string path, int n) {
    if(n == in.length() * 2) {
        /*como el stack se debe llenar y despues vaciar, el n, que cuenta 
        las operaciones de push y pop que se hacen, deberia ser 2*n al final
        entonces se imprime el string path, que contiene la convinacion de i y o.
        Se termina dfs.*/
        if(b == out)
            cout << path << endl;
        return;
    }
    /*Se hace recursividad del dfs,dependiendo si se hace push o pop tenemos: */
    // push
    if(a.length() > 0)
        /* Solo si el tamaño de a es > 0
        a: un sub-string de si mismo, desde la posicion a[1] hasta el término.
        b: no se modifica;
        stack: lo que ya contiene el string + a[0], pues ya se "procesó";
        n: se le suma uno a si mismo, pues se hizo una operación mas;
        */
        dfs(a.substr(1, a.length() - 1), b, \
            stack + a[0], path + (n == 0? "i" : " i"), n + 1);
    // pop
    if(stack.length() > 0 && stack[stack.length() - 1] == out[b.length()])
        /*Para hacer pop, el "stack" no debe estar vacío, y su último elemento
        debe ser igual al del string al que se quiere llegar, si no no es posible
        el anagrama.
        a: no se hace cambio, pues la letra aun no se procesa;
        b: se suma a si mismo la última letra del stack
        stack: se hace un substring de si mismo, desde el inicio al tamaño-1;
        path: a si mismo se le añade el termino " o" que significa pop;
        n: se le suma 1, porque se hizo una operacion;
        */
        dfs(a, b + stack[stack.length() - 1], \
            stack.substr(0, stack.length() - 1), \
            path + " o", n + 1);
}
 
int main() {
    while(cin >> in >> out) {
        printf("[\n");
        if(in.length() == out.length())
            dfs(in, "", "", "", 0);
        printf("]\n");
    }
}
/*
Main: se lee el par de strings, imprime "[" y compara el tamaño de los string, 
en caso se ser iguales, se llama la funcion "dfs", esto significa que si es que 
los strings tienen el mismo tamaño, pueden ser anagramas, en caso contrario, no 
tienen posibilidades de serlo, entonces se imprime directamente "]".
*/