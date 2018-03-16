/**
	UVa 450 - Little Black Book
	by Rico Tiongson
	Submitted: May 12, 2013
	Accepted 0.092s C++
	O(nlogn) time
*/
#include <iostream>
#include <map>

using namespace std;

/*
el problema consiste en que entregada la informacion un numero de departamentos, donde trabajan un numeros de personas,
ordenar a las personas por el apellido e imprimir la informacion entregada con el formato especificado en el problema
*/


/*
d[0] mrs/dr..
d[1] nombre pila
d[2] apellido
d[3] direccion
d[4] numero de la casa
d[5] numero del trabajo
d[6] box del campus
d[7] deparmento
*/

struct Info {
    string d[8];
};


int main() {
    int t;

    string depart, info;
    // en el map se almacenan, por el nombre del departamenteo y por la informacion, 
    //donde la informacion es un array de string, q contienen los datos de las personas
    map<string, Info> r;
    // t numero de departamentos
    cin >> t;

    cin.ignore();

    while(t--) {
            // se lee departamento correspondiente
        getline(cin, depart);
            // se almacena la informacion correspondiente
        while(getline(cin, info)){
            if(info.length() == 0)
                break;
            // pos_1, corresponde al inicio del array
            // pos_2  corresponde a la posicion donde se encuentra la coma,

            // se debe notar de la entrada que los datos, son separados por comas entre ellos.
            int pos_1 = 0, 
                pos_2 = info.find(",");
            // sirve para ir accediendo a las disintas posiciones info, para ir asignando la informacion a medida q es leida
            int idx = 0;
            
            Info p;
            // el while, divide la informacion, para ser ingresada en los campos correspondientes
            while(true){
                    // obtiene los substring, con los datos
                string sub = info.substr(pos_1, pos_2-pos_1);

                p.d[idx++] = sub;
                pos_1 = pos_2 + 1;
                pos_2 = info.find(",", pos_2 + 1);
                if(pos_2 == string::npos) {
                    sub = info.substr(pos_1, pos_2-pos_1);
                    p.d[idx++] = sub;
                    break;
                }
            }
            // corresponde a la asginacion de departamento con el q se esta trabajando actualmente
            p.d[7] = depart;
                // almacena en el map, por el orden de apellido, asi se mantiene ordenado
            r[p.d[2]] = p;
        }
    }


    // esta parte corresponde al formato con el que se imprimen, los distintos casos que fueron leidos
    for(map<string, Info>::iterator i = r.begin(); i != r.end(); i++) {
        cout << "----------------------------------------" << endl;
        Info p = i->second;
        cout << p.d[0] << ' ' << p.d[1] << ' ' << p.d[2] << endl;
        cout << p.d[3] << endl;
        cout << "Department: " << p.d[7] << endl;
        cout << "Home Phone: " << p.d[4] << endl;
        cout << "Work Phone: " << p.d[5] << endl;
        cout << "Campus Box: " << p.d[6] << endl;
    }
}