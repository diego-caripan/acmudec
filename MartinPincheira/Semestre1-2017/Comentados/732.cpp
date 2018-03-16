#include <stdio.h>
#include <string.h>

char a[105], b[105], buf[105];
char stk[105], w[105];
int len, stkIdx;

//Esta funcion tiene la funcion de verificar cada caracter del string, almacenando en un arreglo (w) la secuencia de i's y
//o's que se necesitan para

void dfs(int idx, int i, int o){

	//Caso base de la funcion recursiva, en donde se imprime cada caracter i y o para luego finalizar.
	if(i == len && o == len){
		
		for(int j = 0; j < idx; j++){
			
			if(j) putchar(' ');
			putchar(w[j]);
		}

		puts("");
		return ;

	}

	//Este caso se realiza para guardar la cantidad de caracteres i en el arreglo w necesarios, por medio de de las
	//variables idx, i y o.
	if(i < len){

		stk[stkIdx++] = a[i];
		w[idx] = 'i';
		dfs(idx+1, i+1, o);
		stkIdx--;
	}

	//Este caso se encarga de guardar el caracter o en el arreglo w.
	if(i > o){
		//Se verifica si el ultimo caracter ingresado a stk es igual al primer carater de la palabra objetivo, esto
		//para poder realizar el ingreso de los caracteres o correspondientes.
		if(stk[stkIdx-1] == b[o]){
			w[idx] = 'o';
			stkIdx--;
			dfs(idx+1, i, o+1);
			stkIdx++;
			stk[stkIdx-1] = b[o];
		}
	}
}

int main(){
	//Se realiza la lectura de ambas palabras
	while(gets(a)){

		gets(b);
		puts("[");
		len = strlen(a), stkIdx = 0;
		//Se verifica que ambas palabras sean del mismo tamaño, ya que si no es asi no se puede convertir la palabra
		//fuente en la palabra objetivo.
		if(strlen(a) == strlen(b))
			dfs(0,0,0);
		puts("]");
	}

	return 0;
}
