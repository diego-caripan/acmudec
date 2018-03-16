#include <iostream>
using namespace std;
/*
El problema trata sobre encontrar donde esta un cierto punto en el tablero esperal,
donde los moviemtos no se dan de forma tradicional
*/
//define dos tipos de for, para ser mas practico
#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
//una estructura que defina la locacion
enum direction {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};
/*
funcion que devulve un dato par, con la locacion requerida
tomando en cuenta que el primer elemento esta en el centro,
y se mueve en esperal el tablero, primero a la arriba y luego izquierda
*/
pair<int,int> compute_position(int sz, long long p) {
    int x, y;
    direction dir;

    // starting position where 1 is
    x = y = sz / 2 + 1;
    // starting direction is top
    dir = TOP;
    
    if (p == 1) {
        return make_pair(x, y);
    }

    int increment = 1;
    int count = 2;
    long long current = 1;

    while (true) {
        if (current + increment >= p) {
            increment = p - current;
        }

        count--;
        current += increment;
        //dependiendo el caso devide donde esta
        switch (dir) {
            case TOP:
                x += increment;
                dir = LEFT;
                break;
            case BOTTOM:
                x -= increment;
                dir = RIGHT;
                break;
            case LEFT:
                y -= increment;
                dir = BOTTOM;
                break;
            case RIGHT:
                y += increment;
                dir = TOP;
                break;
        }

        if (count == 0) {
            increment++;
            count = 2;
        }
        //si se llego al punto se sale dle while
        if (current == p)
            break;
    }

    return make_pair(x, y);
}

int main(void) {
    int sz;
    long long p;

    while (cin >> sz >> p) {
        if (sz == 0 && p == 0)
            break;

        pair<int,int> result = compute_position(sz, p);

        cout << "Line = " << result.first << ", column = " << result.second << "." << endl;
    }

    return 0;
}