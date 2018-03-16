#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

//Se crea esta estructura para almacenar la informacion por separado de cada persona, para asi despues desplegarlo de
//forma ordenada.
struct Info {
	string d[8];
};

int main() {

	int t;
	string depart, info;
	map<string, Info> r;
	cin >> t;

	getchar();

	while(t--) {
		//Se almacena el departamento en el string depart
		getline(cin, depart);
		
		while(getline(cin, info)) {

			if(info.length() == 0)
				break;

			int pos_1 = 0, pos_2 = info.find(",");
			int idx = 0;
			Info p;

			while(1) {
				//Lo que se realiza en este while es separar la informacion obtenida por la linea ingresada
				//separandola, esto por medio de tomar el substring hasta encontrar el simbolo ","
				//lo cual indica que es una informacion adicional. Luego se recalcula las posiciones
				//para seguir obteniendo y separando la informacion.
				string sub = info.substr(pos_1, pos_2-pos_1);
				p.d[idx++] = sub;
				pos_1 = pos_2 + 1;
				pos_2 = info.find(",", pos_2 + 1);
				
				//Esta verificacion se realiza para cuando la posicion 2 haya sobrepasado el final del string
				//inicial para lo cual se obtiene el ultimo dato ingresado.
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

	//En este for y por medio de un iterador sobre r se imprime la informacion segun el orden que se impone, accediendo
	//a la informacion previamente separada para cada persona. 
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
