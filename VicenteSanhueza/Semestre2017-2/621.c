#include <stdio.h>
#include <string.h>

int main() {
	int n,tam,i;
	char s[1000];

	scanf("%d", &n);
	for(i=n; i>0 ;i--){
		scanf("%s",&s[0]);
		tam=strlen(s);

		if(s[tam-1] == '5'){
			printf("-\n");
		}else{
			if(s[0] == '9' && s[tam-1] == '4'){
				printf("*\n");
			}else{
				if(s[0] == '1' && tam >= 3){
					printf("?\n");
				}else{
					printf("+\n");
				}
			}
		}
	}
	return 0;
}