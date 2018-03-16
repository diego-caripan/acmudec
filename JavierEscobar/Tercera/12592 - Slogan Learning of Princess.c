#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n,q,i,j,l,s=101;
	char **firstLine=malloc(2020), **secondLine=malloc(2020), *currLine=malloc(101);
	scanf("%d\n",&n);
	/*printf("%d\n",n);*/
	for(i=0; i<n; i++ ){
		firstLine[i]=malloc(101);
		l=getline(&firstLine[i], (size_t*)&s, stdin);
		/*printf("%d\n",l);*/
		if(firstLine[i][l-1]=='\n'){
			firstLine[i][l-1]='\0';
		}
		/*puts(firstLine[i]);*/
		secondLine[i]=malloc(101);
		l=getline(&secondLine[i], (size_t*)&s, stdin);
		/*printf("%d\n",l);*/
		if(secondLine[i][l-1]=='\n'){
			secondLine[i][l-1]='\0';
		}
		/*puts(secondLine[i]);
		puts("------------");*/
	}
	scanf("%d\n",&q);
	for(i=0;i<q;i++){
		l=getline(&currLine, (size_t*)&s, stdin);
		if(currLine[l-1]=='\n'){
			currLine[l-1]='\0';
		}
		for(j=0;j<n;j++){
			if(!strcmp(currLine, firstLine[j])){
				puts(secondLine[j]);
				/*puts("found");*/
				break;
			}
		}
		/*printf("%d",i);*/
	}
	free(firstLine);
	free(secondLine);
	free(currLine);		
	return 0;
}