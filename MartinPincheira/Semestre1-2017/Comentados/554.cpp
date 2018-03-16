#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	
	char s[1024], d[1024];
	map<string, int> R;

	//Se obtienen las palabras posibles y se almacenan en el map R, asignandole un valor inicial 0.
	while(gets(s)) {

		if(!strcmp(s, "#"))
			break;
	
		R[s] = 0;
	}

	gets(s);
	
	int i, j, k, len = strlen(s);
	string res;
	int mxcnt = -1;

	for(i = 1; i < 27; i++) {
		//En este paso se realiza la transformacion del string de entrada en el posible string de salida
		//por medio de la verificacion de los caracteres y la aplicacion de modulo 27.
		for(j = 0; j < len; j++) {

			if(s[j] == ' ') k = 0;
			else k = s[j]-'A'+1;

			k = (k-i+27)%27;			

			if(k == 0) d[j] = ' ';
			//Se almacena el valor del caracter equivalente en ASCII que es calculado con anterioridad.
			else d[j] = k+'A'-1;
		}

		d[len] = '\0';

		stringstream sin(d);
		string token;
		int cnt = 0;

		while(sin >> token) {
			//Se utiliza el iterador sobre R para encontrar coincidencias entre el string obtenido por token
			//desde sin, y las posibles palabras que pueden estar presentes en el string final.
			map<string, int>::iterator it = R.find(token);

			if(it != R.end())
				cnt++;
		}

		if(cnt > mxcnt)
			res = d, mxcnt = cnt;
	}

	stringstream sin(res);
	string token;
	int col = 0;
	int first = 0;

	while(sin >> token) {
		//Se realiza la verificacion de los caracteres en mayuscula, para luego ser impresos.
		if(col + token.length() >= 60)
			cout << endl, col = 0, first = 0;
		
		if(first) putchar(' ');
		
		first = 1;
		col += first + token.length();
		cout << token;
	}

	cout << endl;

	return 0;
}
