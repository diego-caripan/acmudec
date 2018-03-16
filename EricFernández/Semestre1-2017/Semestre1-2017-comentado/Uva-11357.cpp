#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//define sus propias funciones para ahorrar espacio despues
#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int cases;
    string input;
    int vars[30];
    bool possible;
    //lee y limpia el buffer de lectura
    cin >> cases;
    cin.ignore(100, '\n');

    while (cases--) {
        //lee el input
        getline (cin, input);

        stringstream ss(input);
        vector<string> formulas;

        while (getline (ss, input, '|')) {
            input.erase (input.begin(), input.begin()+1);
            input.erase (input.begin() + input.size() - 1, input.end());
            //pushea las formulas que hay en el input en un vector
            formulas.push_back(input);
        }
        //revisa las formulas de ser posble
        rep (i, formulas.size()) {
            rep (j, 30) vars[j] = -1;

            input = formulas[i];

            possible = true;

            rep (j, input.size()) {
                char ch = input[j];
                //verifica si es correcto los datos ingresados
                if (ch >= 'a' && ch <= 'z') {
                    if (vars[ch-'a'] == -1) vars[ch-'a'] = 1;
                    else if (vars[ch-'a'] == 1) continue;
                    else {
                        possible = false;
                        break;
                    }
                    //en caso que no siga un caracter, si no una negación
                } else if (ch == '~') {
                    j++;
                    ch = input[j];
                    if (vars[ch-'a'] == -1) vars[ch-'a'] = 0;
                    else if (vars[ch-'a'] == 0) continue;
                    else {
                        possible = false;
                        break;
                    }
                } else if (ch == '&') {
                    continue;
                }
            }
            //si ya no es posible rompe el ciclo
            if (possible) break;
        }
        //imprime la respuesta de acuerdo si es posible o no
        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}