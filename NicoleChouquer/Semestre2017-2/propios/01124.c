#include <stdio.h>
#include <stdlib.h>


int main(){
    
    char c = 'a';
    
    while(c!=EOF){
        c = getchar();
        if(c!=EOF){
        printf("%c",c);
        }
    }
    
    return(0);
}