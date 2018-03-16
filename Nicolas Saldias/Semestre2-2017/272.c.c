#include <stdio.h>
int main(){
	char c;
	int cont;
	while(scanf("%c",&c)!=EOF){
		if(c=='"'){
			if(c=='"' && cont==1){
				printf("''");
				cont=0;
			}else if(c=='"'){
				printf("``");
				cont++;
			}
		}else{
			printf("%c",c);
		}
	}
	return 0;
}