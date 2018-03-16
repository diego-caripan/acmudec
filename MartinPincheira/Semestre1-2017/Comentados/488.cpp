#include <cstdio>

using namespace std;

int main(){

	int tc, f, a;
	
	scanf("%d", &tc); //Numero de casos
	
	while(tc--){
	
		scanf("%d\n%d", &a, &f);
		
		//El primer se encarga de realizar la cantidad de triangulos.
		for(int i = 0; i < f; i++){
			//El segundo for con variable j se encarga de tener el numero que corresponde a cada linea de
			//triangulo.
			for(int j = 1; j <= a; j++){
				//El tercer for con variable k se encarga de ver la altura que le corresponde a cad valor
				//de j.
				for(int k = 0; k < j; k++){
					printf("%d", j);
				}

				printf("\n");
			}
			//Este for realiza lo mismo que el anterior solo que va decreciendo la altura.
			for(int j = a - 1; j >= 1; j--){

				for(int k = 0; k < j; k++){
	
					printf("%d", j);
				}
	
				printf("\n");
			}
			//Salto de linea entre ambos triangulos.
			if(i != f - 1)
				printf("\n");
		}

		if(tc)
			printf("\n");
	}

	return 0;
}
