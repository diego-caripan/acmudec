#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int res;
}Numeros;


int cmp(const void *a,const void *b){
    Numeros c,d;
    c = *(Numeros*)a;
    d = *(Numeros*)b;
    if (c.res != d.res){
        return c.res>d.res?1:-1;
    }else{
        if(c.num%2==0 && d.num%2==0){  
            if(c.num != d.num) return c.num>d.num?1:-1;
            return 0;
        }else if ((c.num%2==1||c.num%2==-1) && (d.num%2==1||d.num%2==-1)){
            if (d.num != c.num) return c.num>d.num?-1:1;
            return 0;
        }else if ((c.num%2==1||c.num%2==-1) && d.num%2==0){
            return -1;
        }else{
            return 1;
        }
    }
}


int main(void){
    int n,m,i;
    while(1) {
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        Numeros v[n];
        for(i=0; i<n ;i++){
            scanf("%d",&v[i].num);
            v[i].res=v[i].num%m;
        }
        qsort(&v[0],n, sizeof(Numeros), cmp);
        printf("%d %d\n",n,m);
        for(i=0; i<n ;i++) printf("%d\n",v[i].num);
    }
    printf("0 0\n");
    return 0;
}