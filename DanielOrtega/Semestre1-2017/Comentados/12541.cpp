#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

/*el problema consiste en encontrar a la persona mas vieja y a la persona mas joven*/

//por lo cual se hace una busqueda mediante se realiza la insercion, comparando a medida que los elementos son insertados
//para esto, se genera un entero que relaciona los dias los meses y el año, para asi obtener un solo numero y asi hacer mas rapida la comparacion

int main() {

    int casos;

    while (cin.eof()) {
        cin >> casos;

        int old = 0, njoven = INT_MAX;
        string viejo, joven, nombre;

        int dd, mm, yy;

        while (casos--) {

            cin >> nombre >> dd >> mm >> yy;
            dd = dd + mm * 100 + yy * 10000;

            if (dd > old) {
                old = dd;
                viejo = nombre;
            }

            if (dd < njoven) {
                njoven = dd,
                joven = nombre;
            }

        }
        cout << viejo << endl;
        cout << joven << endl;
    }
    return 0;
}