#include <stdio.h>
int main(){
	long long int numero;	
	while(scanf("%lld",&numero) == 1){
		if(numero==0){
			break;
		}else{
			while(numero>10){
			numero=numero%10+numero/10;
			}
		}
		printf("%lld\n",numero);
	}
	return 0;
}
