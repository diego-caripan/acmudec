#include <cstring>
#include <iostream>
#include <string.h>


using namespace std;

int fibonacci[] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,
 1597,2584,4181,6765,10946,17711,28657,46368,75025,
 121393,196418,317811,514229,832040,1346269,
 2178309,3524578,5702887,9227465,14930352,24157817,
 39088169};




int main(){


char auxiliar[300];

int casos,numeros,fibo[101];

	
	scanf("%d",&casos);
	while(casos--){

		scanf("%d",&numeros);

	for(int i =0; i< numeros; i++){
		scanf("%d",&fibo[i]);
		}
	getchar();
	fgets(auxiliar,300,stdin);
	getchar();


	for(int i =0 ; i < numeros;i++){
		cout << fibo[i] << "\n";
	}

int posicion;
int tamano = strlen(auxiliar);
char palabra[101]; 
cout << "tamano:" <<tamano << endl;
palabra[numeros] = '\0';

	
cout << "IMPRIMIR\n";
int cont=0;
for(int i =0; i< tamano; i++){
	if(auxiliar[i]>=65 && auxiliar[i] <= 90){
		//cout << auxiliar[i];
				cout << "fibo " <<fibo[cont] << "\n";
		for(int j = 0; j<38;j++){
			if( fibo[i] == fibonacci[j]){
				posicion = j;
			cout<< posicion << endl;
				cont++;
			}
		}
		palabra[posicion]= auxiliar[i];
		//strcpy(palabra[posicion],auxiliar[i]);
	}

}

	printf("%s\n",palabra);

	}


return 0;
}