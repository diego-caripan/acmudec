#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int cont, ant,dif,K,acont;
        cont = ant = dif = K = acont = 0;
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            if(num - ant == K) K--;
            else if(num - ant > K) acont++; 
            if(dif == num-ant){
                 cont++;
                 K = dif - 1;
                 acont = 0;
            }
            else if(dif<num-ant){
                 dif = num-ant;
                 K = dif - 1;
                  cont = 0;
                  acont = 0;
                 }
                ant = num;
            }
        if(cont>0) cont = 1;
        else if (cont == 0 && acont > 0) cont = 1;
        int res = dif + cont;
        printf("Case %d: %d\n",i+1,res);
    }
    return 0;
}