#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        int b;
        scanf("%d",&b);
        int cont=0;
        int ant=0;
        int dif=0;
        int lolen=0;
        int lol = 0;
        for(int i=0;i<b;i++){
            int num;
            scanf("%d",&num);
            if(num - ant == lolen) lolen--;
            else if(num - ant > lolen) lol++; 
            if(dif == num-ant){
                 cont++;
                 lolen = dif - 1;
                 lol = 0;
            //     printf("num = %d y ant = %d y cont = %d\n",num,ant,cont);
            }
            else if(dif<num-ant){
                 dif = num-ant;
                 lolen = dif - 1;
                  cont = 0;
                  lol = 0;
              //     printf("num = %d y ant = %d y dif = %d\n",num,ant,dif);
                 }
                ant = num;
            }
        if(cont>0) cont = 1;
        else if (cont == 0 && lol > 0) cont = 1;
        int res = dif + cont;
        printf("Case %d: %d\n",j+1,res);
    }
    return 0;
}