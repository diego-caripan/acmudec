#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* a, const void* b){		//funcion que me ayuda a ordenar el vector
    return *(int*)a- *(int*)b;
}

int main(){
    long long int v[10000];
    long long int sobras,i,hechas,l,total;
    long long int caso,aux;	//Numero de casos
    scanf("%lld",&aux);
    for(caso=1; caso<=aux ;caso++){
        scanf("%lld %lld",&hechas,&sobras);	//en hechas: galletas hechas, sobras: galletas sobrantes;
        total=hechas-sobras;				//cuantas galletas se comieron
        if(hechas==sobras){
            printf("Case #%lld: 0\n",caso);   //imprimo cuando son iguales         
        }else{
	    l=0;
            printf("Case #%lld:",caso);            
            for(i=1; i<=sqrt(total) ;i++){
                if((total%i) == 0){                    
                    v[l]= i;    
                    l++;
                    if((total/i) != i){
                        v[l] = total/i;
                        l++;
                    }
                }
            }
            qsort(&v[0],l,sizeof(long long int),cmp);		//Aqui ordeno el arreglo
            for(i=0;i<l;i++) if(v[i]>sobras)printf(" %lld",v[i]);	//recorro el vector viendo los correctos, y los imprimo
            printf("\n");
        }
    }
    return 0;
}