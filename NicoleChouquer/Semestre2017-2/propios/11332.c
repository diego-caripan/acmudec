#include <stdio.h>
#include <string.h>

int main() {
  
    long int x = 1;
    char num[11];
    long int suma = 0;
    int aux;
    int l;
    int i=0;
    
    while(x!=0){
        
    scanf("%ld\n",&x);
    sprintf(num,"%ld",x);
    l = strlen(num);
    
    
        do{
        
        for(i=0; i<strlen(num);i++){
              aux = num[i]-'0';
              suma = suma + aux;
        }
        
        sprintf(num,"%ld",suma);
        l = strlen(num);
        if(l==1){
            if(suma!=0){
            printf("%ld\n",suma);
            }
        }
        suma = 0;
    }while(l!=1);
    
  
    }
    
    return (0);
}