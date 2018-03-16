//codigo comentado
//Fuente : https://github.com/Diusrex/UVA-Solutions/blob/master/10878%20Decode%20the%20tape.cpp
#include <iostream>
#include <string>

using namespace std;


int main(){
    string temp;
    getline(cin, temp); // lee la primera linea y la guarda en temp
    while (temp[0] != '|')  // si el primer elemento de la linea leida no es el simbolo '|' la vuelve a leer
        getline(cin, temp);
    while (temp[0] == '|'){  // mientras el primer elemento sea igual a ese simbolo
        int pos(7); //ya que el maximo de espacios son 7
        int value(0);
        for (string::const_iterator c = temp.begin() + 1; pos >= 0; ++c){ //comienza a leer desde el segundo elemento de temp y va aumentando
            if (*c == ' ' || *c == 'o'){ 
                if (*c == 'o') value += (1 << pos);   // si el valor obtenido es un 'o' aumenta el valor de la letra   
                --pos; //disminute la poscion
            }
        }
        cout << static_cast<char>(value); //hace que el valor numerico se transforme en caracteres
        getline(cin, temp); // lee la siguiente linea y la guarda en temp
    }

}