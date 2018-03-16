#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int t,i,j,nTests, nDays, nParty, daysLost;
	int hartals[100];
	scanf("%d", &nTests);
	for(t=0; t<nTests; t++){
		scanf("%d", &nDays);
		scanf("%d", &nParty);
		for(j=0; j<nParty; j++){
			scanf("%d",&hartals[j]);			
		}
		daysLost=0;
		for(i=1; i<=nDays; i++){
			if(i%7==0 || i%7==6){
				continue;
			}
			for(j=0; j<nParty; j++){
				if(i%(hartals[j])==0){
					daysLost++;						
					break;					
				}
			}			
		}
		printf("%d\n", daysLost);
	}
	return 0;
}