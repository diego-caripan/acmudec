#include <stdio.h>

int main(){
	int curr, acc;
	while(1){
		acc=0;
		scanf("%d", &curr);
		if(curr==0){
			break;
		}
		while(1){
			acc += curr%10;			
			curr=curr/10;
			if(curr==0){
				if(acc/10==0){
					printf("%d\n", acc);
					break;
				}
				else{
					curr = acc;
					acc = 0;
				}
			}
		}
	}
	return 0;
}