#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;
//estrectura dodne se guardan los datos
struct Info {
    string d[8];
};
/*
Dado entradas ordenar por informacion
*/
int main() {
    int t;
    string depart, info;
    //en el mapa se ordenan alfabeticamente
    //ademas el campo valor son los datos de la persona
    map<string, Info> r;
    cin >> t;
    getchar();
    //lee la cantidad de casos
    while(t--) {
        //va leyendo los datos hasta entoncrar una ',' y luego continua hasta la otra ','
        //y los guarda en Info del lugar del mapa al que corresponden
        getline(cin, depart);
        while(getline(cin, info)) {
            if(info.length() == 0)
                break;
            int pos_1 = 0, pos_2 = info.find(",");
            int idx = 0;
            Info p;
            while(1) {
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
            p.d[7] = depart;
            r[p.d[2]] = p;
        }
    }
    //imprime la infomacion de cada persona
    for(map<string, Info>::iterator i = r.begin(); i != r.end(); i++) {
        cout << "----------------------------------------" << endl;
        Info p = i->second;
        cout << p.d[0] << " " << p.d[1] << " " << p.d[2] << endl;
        cout << p.d[3] << endl;
        cout << "Department: " << p.d[7] << endl;
        cout << "Home Phone: " << p.d[4] << endl;
        cout << "Work Phone: " << p.d[5] << endl;
        cout << "Campus Box: " << p.d[6] << endl;
    }
    return 0;
}