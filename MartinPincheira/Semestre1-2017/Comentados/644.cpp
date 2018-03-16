#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

	char temp[100];
	vector <string> input;
	int i,j,k,cnt;
	bool flag;

//Esta función se encarga de checkear si el primer string es prefijo del segundo
bool check(string x,string y){
	
	//Si el primer string es mas largo que el segundo quiere decir que no puede ser prefijo.
	if(x.length()>y.length()) return false;
	
	//Se verifica si el primer string es prefijo del segundo, comparando caracter a caracter, y entregando como resultado
	//verdadero si lo es, y en caso contrario falso.
	for(int i=0;i<x.length();i++)
		if(x[i]!=y[i]) return false;
	return true;
}

int main(){
	//Contador usado para la cantidad de casos ingresados.
	cnt=0;

	//Se utiliza un vector (input) para almacenar los strings que se leen, para poder ser ordenados y comprobar si existen
	//prefijos
	while(scanf("%s",temp)==1){
		
		flag=false;
		input.clear();
		input.push_back(temp);

		while(1){
			cin>>temp;
			//Al leer el digito 9 se detiene la lectura de entradas y push correspondientes.
			if(!strcmp(temp,"9")) break;
			input.push_back(temp);
		}
		//Luego de realizar los push de los string, se ordena el vector para poder facilitar la busqueda de prefijos.
		sort(input.begin(),input.end());
		//Este for itera sobre el vector input, para poder buscar los prefijos por medio de la funcion check.
		for(int i=1;i<(int)input.size();i++){
			//Si el primer string ingresado es prefijo del segundo, esto retornara verdadero, por lo cual flag
			//adoptara el valor verdadero, queriendo decir que si es prefijo.
			if(check(input[i-1],input[i])){
				flag=true;
				break;
			}
		}
		//si flag es falso, quiere decir que ningun string es prefijo de otro, por lo cual es "immediately decodable".
		if(!flag) printf("Set %d is immediately decodable\n",++cnt);

		else printf("Set %d is not immediately decodable\n",++cnt);
	
	}

	return 0;

}
