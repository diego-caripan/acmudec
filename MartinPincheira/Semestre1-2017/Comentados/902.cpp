#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char s[1000001];

int main(){

	//Se utiliza un map para asociar el valor numerico calculado de cada secuencia de N substrings con el numero de
	//ocurrencias del substring en el string original
	int N;
	map<long long, int> cont;

	while(scanf("%d %s",&N,s) == 2){

		int L = strlen(s);
		cont.clear();
	
		//El primer for recorre el string de entrada, corriendo la posicion de busqueda hasta que la posicion
		//actual mas el tamaño del substring (correspondiente a la clave) no sobrepase el largo de este.
		for(int i = 0;i + N <= L;++i){

			long long aux = 0;
			
			//Por cada letra leida se calcula el valor de mapeo, con su respectivo valor de las ocurrencias
			//esto N veces, que corresponde al largo de la clave.
			for(int j = 0;j < N;++j){
				aux = aux*26 + (s[i+j]-'a');
			}
			
			cont[aux]++;
		}

		long long ans_hash;
		int best = -1;

		//Aqui se hace una busqueda lineal en el map, en donde se selecciona el valor con mas ocurrencias.
		for(map<long long, int> :: iterator it = cont.begin();it != cont.end();it++){

			if(it->second > best){
				ans_hash = it->first;
				best = it->second;
			}
		}
		
		string ans;
	
		//Luego de obtener el valor se reconstruye hacia atras la clave que se busca, tomando el primer valor de map,
		//almacenado en ans_hash, por medio de divisiones y restando el caracter a, esto porque el valor fue 
		//construido de esa manera anteriormente.
		for(int i = 0;i < N;++i){

			ans = (char)(ans_hash % 26 + 'a') + ans;
			ans_hash /= 26;
		}

		puts(ans.c_str());
	}

	return 0;
}
