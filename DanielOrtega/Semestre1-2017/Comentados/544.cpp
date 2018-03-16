

/*
EL problema consiste en que dado una lista de palabras a buscar, esta sean encontradas en un string de busqueda,
este string de busqueda, es un string que se encuentra "cifrado", con el metodo del cifrado cesar, que corresponde a un desplazamiento
en el abecedario, por lo que nuestra tarea consiste en:
generar todas los desplazamientos posibles del string que cifrado, con el metodo cesar, y tratar de encontrar las palabras a buscar en ella,
nos quedamos con el desplazamiento que tenga la mayor cantidad de coincidencias


*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
//key define el abecedario

char                key[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector < string >   dic;
string              cipher;


// busca el indice de la palabra en el abecedario, sirve para buscar en key[]
inline int index(char c) {
    return (c == ' ') ? 0 : (c - 'A' + 1);
}

// buscar permite y comparando, ya que entrega el caracter, pero considerando que da vueltas en el key[]
inline char trans(char c, int i) {

    return key[(index(c) + i) % 27];
}

/*
Esta funcion se encarga de imprimir la salida del string que se obtiene en solve,
*/

void output(string s) {
    int     counter = 0;
    char*   str = (char*)s.c_str();
    char*   ptr;
    //incializa ptr con un espacio
    ptr = strtok(str, " ");
    cout << ptr;
    // counter, es una variable que se va incrementando a medida que se van leyendo los caracteres que se van leyendo
    counter = strlen(ptr);
    // 
    while ((ptr = strtok(NULL, " ")) != NULL) {
        if (counter + strlen(ptr) >= 60) {
            cout << endl;
            counter = strlen(ptr);
        }
        else {
            cout << ' ';
            counter += strlen(ptr) + 1;
        }

        cout << ptr;
    }

    cout << endl;
}

/*
esta funcion se encarga de resolver

*/
void solve(void) {

    int     match[27];
    string  plain;

    for (int i = 0; i < 27; i++) {
        plain = cipher;
        // genera una desplazamientos en el "cifrado", por cada i, donde cada i corresponde al desplazamiento en 1 posicion
        for (int j = 0; j < plain.length(); j++)
            plain[j] = trans(plain[j], i);

        int     counter = 0;
        char*   str = (char*)plain.c_str();
        char*   ptr;
        // busca, por la palabra modificada y ve si se encuentra en algun punto de la palabra "cifrada"
        ptr = strtok(str, " ");
        if (find(dic.begin(), dic.end(), ptr) != dic.end())
            counter++;

        while ((ptr = strtok(NULL, " ")) != NULL) {
            if (find(dic.begin(), dic.end(), ptr) != dic.end())
                counter++;
        }
            // lleva un conteo de la cantidad de palabras que hacen match, por el desplzamiento correspondiente a esa iteracion
        match[i] = counter;
    }
        // k corresponde al numero correcto del desplazamiento 
    int K = max_element(match, match + 27) - match;

    
    plain = cipher;
        // modifica el mensaje "cifrado" descodificandolo, y pasandoselo a la funcion, que lo imprimira
    for (int i = 0; i < plain.length(); i++)
        plain[i] = trans(plain[i], K);

    output(plain);
}


int main(void)
{   // obtiene la lista de palabras a buscar y las almacena en un vector
    while (true) {
        string  tmp;

        getline(cin, tmp);
        if (tmp[0] == '#')
            break;

        dic.push_back(tmp);
    }
    // obtiene el cifrado
    getline(cin, cipher);

    solve();

    return 0;
}