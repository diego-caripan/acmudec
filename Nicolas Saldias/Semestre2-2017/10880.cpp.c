#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>

int main(){
long long int a[10000];
    long long int n, i, t, j=0, p, l, q;
    scanf("%lld",&t); // lee la cantidad de casos
    while(t--){
        scanf("%lld %lld",&p,&n);// lee la cantidad de galletas que se hicieron y las que quedaron
        q = p-n; // calcula la diferencia
        l=0;
        if(p==n) printf("Case #%lld: 0\n",++j); // caso en que las que quedan son iguales a las que se hicieron
        else{
            printf("Case #%lld:",++j);

            for(i=1;i<=sqrt(q);i++){//calcula los divisores de q
                if(q%i==0){
                    a[l++]= i;
                    if(q/i!=i) a[l++] = q/i;
                }
            }
            sort(a,a+l); // ordena los divisores
            for(i=0;i<l;i++){
                 if(a[i]>n) // revisa que los divisores sean mayor al numero de galletas que quedaron
                   printf(" %lld",a[i]); // imprime los divisores correctos
             }
             printf("\n");
        }
    }
    return 0;
}