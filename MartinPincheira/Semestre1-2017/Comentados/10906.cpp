#include <stdio.h>
#include <map>
#include <iostream>

using namespace std;

//Se crea esta estructura para poder almacenar los simbolos terminales y no terminales de cada expresion, los cuales
//se van actualizando al llegar a los terminales.
struct E {
	string A, B, C; // A (C) B
};

map<string, E> R;

string dfs(string val) {

	E &v = R[val];
	string ret = "", right, left;

	//Si el elemento ingresado en el string A corresponde a un valor numerico o tambien llamado terminal, este se
	//almacena inmediatamente en el string left, para luego ser concatenado con otros valores o simbolos. Si no es el
	//caso, entonces llama nuevamente a la funcion pero ahora con el elemento no terminal, de forma recursiva.
	if(v.A[0] >= '0' && v.A[0] <= '9')
		left = v.A;

	else
		left = dfs(v.A);
	
	//Lo mismo que se define anteriormente se aplica para el string B.
	if(v.B[0] >= '0' && v.B[0] <= '9')
		right = v.B;
	
	else
		right = dfs(v.B);

	//Si el string C, que sera el que almacena el elemento correspondiente a la operatoria a realizar es un "+",
	//este es concatenado con el string left que ya contiene o una expresion o solo un valor numerico.
	if(v.C == "+") {
		ret = left + "+";
		//Si el string B es un valor numerico(terminal) entonces se concatena con lo anterior, de lo contrario se
		//añaden al string de salida parentesis, puesto que corresponde a otra operacion.
		if(v.B[0] >= '0' && v.B[0] <= '9')
			ret = ret + right;
		
		else
			ret = ret + "(" + right + ")";

	cout << ret << endl;
	} else { // v.C == "*"

		int i, flag = 0, l = 0, flag2 = 0;
		
		//Aqui se realiza un contador de parentesis y verificar si despues del ultimo parentesis
		for(i = 0; i < left.length() && !flag; i++) {		

			if(left[i] == '(') l++;
			if(left[i] == ')') l--;
			if(l == 0 && left[i] == '+')
				flag = 1;
	
		}

		//Si el ultimo caracter leido es un "+" quiere decir que esa operacion debe ir dentro de un parentesis,
		//en el caso contrario de que solo fuese un valor numerico entonces se añade el simbolo "*"
		if(flag)
			ret = "(" + left + ")*";
	
		else
			ret = left + "*";
		
		i, l = 0;
	
		//Lo mismo ocurre para este caso.
		for(i = 0; i < right.length() && !flag; i++) {
			
			if(right[i] == '(') l++;
			if(right[i] == ')') l--;
			if(l == 0 && right[i] == '+')
				flag2 = 1;
		}

		if(flag == 0 && flag2 == 0)
			ret = ret + "(" + right + ")";

		else
			ret = ret + right;
	}
	
	return ret;
}

int main() {

	int testcase, cases = 0;
	int n, i;

	scanf("%d", &testcase);

	while(testcase--) {
		
		//Se hace la lectura de los elementos y se almacenan
		scanf("%d", &n);
		R.clear();
		char s1[50], s2[50], s3[50], s4[50];
		E tmp;

		for(i = 0; i < n; i++) {

			scanf("%s = %s %s %s", s1, s2, s3, s4);
			tmp.A = s2, tmp.B = s4;
			tmp.C = s3;

			R[s1] = tmp;
		}

		printf("Expression #%d: ", ++cases);

		cout << dfs(s1);
		puts("");
	}

	return 0;
}
