#include <stdio.h>
 
static char t[256];
 
int main(){
    register unsigned i, k, c = 0;
 
    while(gets(t)){
        char a[256] = {'\0'};
 
        for (i = k = 0; t[i]; ++i){
            
            if (t[i] == 34 && !c){
                a[k] = a[k+1] = 96;
                k = k + 2;
                c = 1;
            }else if(c && t[i] == 34){
                a[k] = a[k+1] = 39;
                k += 2;
                c = 0;
            }else{
                a[k] = t[i];
                ++k;
            }
        }
        printf("%s\n", a);
    }
    return 0;
}