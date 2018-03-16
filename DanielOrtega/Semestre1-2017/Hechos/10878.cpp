/* la uva no me acepto el codigo por los espacios, pero la mecanica esta bien */

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int transbit(char aux[]){
	int suma = 0,contador=7;

for(int i =1; i < 10; i++){
	
	if('|' == aux[i] || '.' == aux[i]) {
			continue;	
	}
	else if (' ' == aux[i]) contador--;
	else if ('o' == aux[i]){
		suma+= pow (2, contador);
		contador--;	
}
}


	return suma;
}


int main(){
	 
	char bits[12];

		
	while (fgets(bits, 12, stdin)!=NULL){
			getchar();

	
			printf("%c", transbit(bits));
	

	}

	return 0;
}