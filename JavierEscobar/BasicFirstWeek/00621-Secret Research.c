#include <stdio.h>

int first1(int initial){
	while(initial/10!=0){
		initial = initial/10;
	}
	return initial;
}

int main(){
	int nCases,i=0, curr;
	scanf("%d", &nCases);
	while(i<nCases){
		scanf("%d", &curr);
		if(curr == 4 || curr==78 || curr==1){
			printf("+\n");
		}
		else if(curr%100==35){
			printf("-\n");
		}
		else if(curr%10==4 && first1(curr)==9){
			printf("*\n");
		}
		else {
			printf("?\n");
		}
		i++;
	}
	return 0;
}