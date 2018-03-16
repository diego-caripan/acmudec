#include <iostream>
#include <string>

using namespace std;

int main(){

	//Se utiliza un string para almacenar la linea ingresada que contiene espacion en blancos, "." y o's.
	string temp;
	getline(cin, temp);

	//Aqui se identifica el comienzo de la cinta.
	while (temp[0] != '|')
		getline(cin, temp);

	//Al identificarse el comienzo de la cinta se procede a leerla.
	while (temp[0] == '|'){

		int pos(7);
		int value(0);
		//El iterador sobre el string recorre la cinta de izquierda a derecha.
		for (string::const_iterator c = temp.begin() + 1; pos >= 0; ++c){
			//Se verifica la lectura de espacios en blanco o del caracter 'o', en donde no se toma en cuenta
			//el carater '.'
			if (*c == ' ' || *c == 'o'){
				//Si se encuetra el caracter 'o' se realiza un corrimiento de bits (left shift) de acuerdo al
				//valor actual
				//de pos, esto para obtener el valor equivalente en ASCII de la letra que se quiere
				//decodificar.
				if (*c == 'o')
					value += (1 << pos);
				--pos;
			}
		}	

		//Se realiza el casteo del valor al caracter correspondiente.
		cout << static_cast<char>(value);

		getline(cin, temp);

	}
	
	return 0;
}
