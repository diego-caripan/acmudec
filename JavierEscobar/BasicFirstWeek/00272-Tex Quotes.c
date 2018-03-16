#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	char currChar, pairStatus=0;

	while((currChar=getchar())!=EOF){
		if(!pairStatus){
			if(currChar=='"'){
				printf("``");
				pairStatus=1;
				continue;
			}
			printf("%c",currChar);
		}
		else{
			if(currChar=='"'){
				printf("''");
				pairStatus=0;
				continue;
			}
			printf("%c",currChar);
		}
	}
	return 0;
}
