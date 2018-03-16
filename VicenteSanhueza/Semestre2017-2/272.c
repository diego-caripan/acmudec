#include <stdio.h>

int main(){
	char a;
	int count=0;
	while((scanf("%c",&a)) != EOF){
		if(a == '"'){
			if(count == 1){
				printf("''");
				count=0;
			}else{
				printf("``");
				count=1;
			}
		}else{
			printf("%c",a);
		}
	}
	return 0;
}