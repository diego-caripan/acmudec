#include <stdio.h>

int main(){
    int casos;
    scanf("%d",&casos);
    int lugares;
	int numerito;
    int max[casos];
    int min[casos];
    int i,j;
    for(i=0;i<casos;i++){
        scanf("%d",&lugares);
        for(j=0;j<lugares;j++){
            scanf("%d",&numerito);
			if(j==0){
				max[i]=numerito;
				min[i]=numerito;
			}            
            else if(max[i]<numerito){
                max[i]=numerito;
            }else if(min[i]>numerito){
                min[i]=numerito;
            }
        }
    }
    for(i=0;i<casos;i++){
        printf("%d\n",(max[i]-min[i])*2 );
    }
    return 0;
}
