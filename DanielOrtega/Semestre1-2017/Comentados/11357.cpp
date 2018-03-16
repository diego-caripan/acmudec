#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int var[30];


/*
El problema consiste en que dado una formula boolena, se pueda determinar, si, de alguna manera,
se pueden asginar valores a las variables de tal manera que la formula tenga un valor de verdad, verdadero.

	se nota, que las expresiones pueden estar dividas por por parentesis, osea
	(formula1 ) | (formula2) | (formula3)......
	facilitando asi el calculo ya que esto, nos marca la separacion, para ir evaluando expresiones.



	En este codigo en particular, se cuenta desde el primer (, y hasta el ), luego de esto se procede a llamar a proc,
	con el substring 

	en proc se evalua el valor de verdad, en esta funcion

	se inicializa un array solo con  -1,
	se considera que si se posee un &, se salta el caso, ya que no es tan determinante en el valor de verdad
	si el  caracter ~, se encuentra presente en el string se asigna el valor de como 0, si no se asigna el 1, esto siempre y cuando se lea un -1
	luego de varias si se lee un valor distinto a -1, se retorna un valor 0 falso y 1 verdadero.



	en el main se procede a evaluar con | las distintas operaciones y se entrega YES si esque se encuentra una combinacion que sea verdadera
	y no si no es posible encontrar una combinacion asi


*/

bool proc(string str) {
	for (int i = 0; i < 30; i++) var[i] = -1;
	for (int i = 0; i < str.length(); i++) 
{		if (str[i] == '&') continue;
		if (str[i] == '~') {
			i++;
			if (var[str[i]-'a'] == -1) var[str[i]-'a'] = 0;
			else if (var[str[i]-'a'] == 1) return false;
		} else {
			if (var[str[i]-'a'] == -1) var[str[i]-'a'] = 1;
			else if (var[str[i]-'a'] == 0) return false;
		}
	}
	return true;
}

int main() {
	int T;
	string form;
	cin >> T;
	while (T--){
		cin >> form;
		bool ok = false;
		int last;

		for (int i = 0; i < form.length() && !ok; i++) {
			if (form[i] == '(') last = i;
			// el || evalua como si fuera una operacion cortocircuito, evaluando q si una operacion operacion 
			else if (form[i] == ')') ok = ok || proc(form.substr(last+1, i-last-1));
		}
		
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}