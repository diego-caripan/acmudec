/*
COMENTADO
sacado de: https://saicheems.wordpress.com/2013/08/18/uva-11507-bender-b-rodriguez-problem/
*/
#include <cstdio>
#include <iostream>
#include <map>
 
using namespace std;
 
long L;
string dir, wire;
map<string, map<string, string> > bends;
/*En bends se almacenan todas las combinaciones posibles para doblar el cable
luego solo se usan las coordenadas que se dan de input en el map para encontrar
la dirección correspondiente que debería tener el cable*/
 
int main() {
    bends["+x"]["+y"] = "+y";
    bends["+x"]["-y"] = "-y";
    bends["+x"]["+z"] = "+z";
    bends["+x"]["-z"] = "-z";
    bends["-x"]["+y"] = "-y";
    bends["-x"]["-y"] = "+y";
    bends["-x"]["+z"] = "-z";
    bends["-x"]["-z"] = "+z";
    bends["+y"]["+y"] = "-x";
    bends["+y"]["-y"] = "+x";
    bends["+y"]["+z"] = "+y";
    bends["+y"]["-z"] = "+y";
    bends["-y"]["+y"] = "+x";
    bends["-y"]["-y"] = "-x";
    bends["-y"]["+z"] = "-y";
    bends["-y"]["-z"] = "-y";
    bends["+z"]["+y"] = "+z";
    bends["+z"]["-y"] = "+z";
    bends["+z"]["+z"] = "-x";
    bends["+z"]["-z"] = "+x";
    bends["-z"]["+y"] = "-z";
    bends["-z"]["-y"] = "-z";
    bends["-z"]["+z"] = "+x";
    bends["-z"]["-z"] = "-x";
 
    for(;;) {
        scanf("%d", &L);
        if(L == 0) break;
        L--;
        wire = "+x";
        for(long i = 0; i < L; i++) {
            cin >> dir;
            if(dir != "No")
                wire = bends[wire][dir];
        }
        cout << wire << endl;
    }
}