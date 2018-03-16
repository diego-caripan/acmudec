#include <stdio.h>
int contadordenumeros(long long int x){
	int cont=1;
	while(x/10){
		cont++;
		x=x/10;
	}
	return cont;
}

int recursividad(int x){
	int yomaira=contadordenumeros(x);
	int y;
	int cont=0;
	if(contadordenumeros(x)==1) return x;
	else{
		for(int i=0;i<yomaira;i++){
			y=x%10;
			cont=cont+y;
			x=x/10;
		}	
return recursividad(cont);
}
}


int main(){
	int a;
	long long int num;
	do{	
		scanf("%lld",&num);
		if(num!=0){
			int a=recursividad(num);
			printf("%d\n",a);
	}
	}while(num!=0);
		
	return 0;
}