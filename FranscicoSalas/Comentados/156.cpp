// COMENTARIO 156

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
 
using namespace std;

// Funci�n que retorna un string s con todos sus chars en min�sculas y ordenados, es decir,
// si se ingresa KbAcd como argumento, retornar� abcdk

string lowercaseAndSort(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= ('A' - 'a');
        }
    }
    sort(s.begin(), s.end());
    return s;
}
 
int main () {
    // Se define un vector de strings, donde ir�n las palabras le�das
    vector<string> all;
    // Se define un mapa <string, int> para contar la cantidad de veces que sale una palabra en min�scula con sus chars ordenados
    map<string, int> v;
    for (;;) {
        string in;
        cin >> in;
	// Lee hasta pillar '#'
        if (in.compare("#") == 0) break;
        // guarda el string en el vector
	all.push_back(in);
	// Hace el mapeo de el string con sus chars en min�scula
        v[lowercaseAndSort(in)]++;
    }
    // Ordena el vector de strings	
    sort(all.begin(), all.end());
    // Recorre los elementos del vector, revisando cuantas veces se repiten las imagen�s del elemento con sus chars en min�culas y ordenados.
    // Imprime los elementos que solo han salido 1 vez.
    for (int i = 0; i < all.size(); i++) {
        if (v[lowercaseAndSort(all[i])] == 1) {
            printf("%s\n", all[i].c_str());
        }
    }
}