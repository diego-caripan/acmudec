#include <stdio.h>
#include <string.h>


int main(){
	char s[999];
	scanf("%[^\n]s",s);
	int i;
	int cont=0;
	int largo= strlen(s);
	for(i=0;i<largo;i++){
		if(s[i]=='"'){
			if(cont==0){
				printf("``");
				cont=1;
			}else if(cont==1){
				printf("''");
				cont = 0;

			}
		}else{
		printf("%c",s[i]);
		}
	}
	printf("\n");


	return 0;
}