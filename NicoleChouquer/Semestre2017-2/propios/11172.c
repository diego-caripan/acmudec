#include <stdio.h>

int main(){

	int t;
	int x;
	int y;


	scanf("%d",&t);

	char r[t];

	for(int i=0; i<t; i++){

		scanf("%d %d",&x,&y);

		if(x>y){

			r[i] = '>';

		} else if(x<y){

			r[i] = '<';

		} else {

			r[i] = '=';
		}

	}

	for(int i=0;i<t;i++){
		printf("%c\n",r[i]);
	}

	return(0);
}