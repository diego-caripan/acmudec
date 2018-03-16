
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char c;
	int h = 0;

	while(c!=EOF){

		c=getchar();

		if(c=='"'&&h==0){
			printf("``");
			h++;
		}
		else if(c=='"'&&h==1){
			printf("''");
			h--;
		}

		else{
			printf("%c",c);
		}
	}


	return 0;
}
