#include <cstring>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


char abecedario = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ "}


bool buscak(char palabra[],vector<string> comparar,int  k){

int caracter,caracter1;
string variable;
	int tam_palabra = strlen(palabra);
	int cant_palabras= comparar.size();

	for(int i = 0 ; i < cant_palabras; i ++){
		
		for(int j = 0 ; j < tam_palabra;j++){

			cout << "palabra: " << palabra << "\n";
			cout << "acomparar" << comparar.at(i) <<"\n";
				caracter =  palabra[j]+k;
				variable = comparar.at(i);
				caracter1 = variable[j];

				cout << caracter << " " << caracter1 << "\n";

			if(caracter1 != caracter){
				break;
			}

		}
	}
}


int main(){

//modulo 27

vector<string> palabra; 
char auxiliar[300];

	
	while(scanf("%s",auxiliar) && strcmp(auxiliar,"#")){
		palabra.push_back(auxiliar);
	}
	getchar();
	fgets(auxiliar,300,stdin);

/*	
	for(int i= 0;i< palabra.size();i++){
		cout << palabra.at(i) << endl;
	}	
	cout<< auxiliar << endl;

*/

	for(int i = 0; i < 27; i++){
		cout << " TRABAJANDO CON EL I" << i << endl;
		buscak(auxiliar,palabra,i);
	}


	return 0;

}