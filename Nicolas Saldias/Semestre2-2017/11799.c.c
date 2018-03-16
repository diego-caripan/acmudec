#include <stdio.h>

int main(){
	int casos;
	scanf("%d",&casos);
	int i,j;
	int velocidad[casos];
	int numerito;
	for(i=0;i<casos;i++){
		int mons;
		scanf("%d",&mons);
		for(j=0;j<mons;j++){
			scanf("%d",&numerito);
			if(j==0){
				velocidad[i]=numerito;
			}else if(velocidad[i]<numerito){
				velocidad[i]=numerito;
			}
		}
	}
	for(i=0;i<casos;i++){
		printf("Case %d: %d\n",i+1,velocidad[i]);
	}
	
	
	
	return 0;
}