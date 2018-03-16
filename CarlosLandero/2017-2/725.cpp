#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int digitos[10];
vector<int> valores_N;
vector< vector<int> > resultados;

void init_digitos(){
    for(int i=0;i<10;i++){
        digitos[i] = -1;
    }
}

int verificacion(int abcde, int fghij){
    //printf("%d %d\n",abcde,fghij);
    int a = abcde/10000;
    int b = (abcde%10000)/1000;
    int c = ((abcde%10000)%1000)/100;
    int d = (((abcde%10000)%1000)%100)/10;
    int e = (((abcde%10000)%1000)%100)%10;
    int f = fghij/10000;
    int g = (fghij%10000)/1000;
    int h = ((fghij%10000)%1000)/100;
    int i = (((fghij%10000)%1000)%100)/10;
    int j = (((fghij%10000)%1000)%100)%10;

    if(a==b || a==c || a==d || a==e || b==c || b==d || b==e || c==d || c==e || d==e){
        return -1;
    }
    if(f==g || f==h || f==i || f==j || g==h || g==i || g==j || h==i || h==j || i==j){
        return -1;
    }

    digitos[f] = f;
    digitos[g] = g;
    digitos[h] = h;
    digitos[i] = i;
    digitos[j] = j;

    for(int q=0;q<10;q++){
        //printf("%d ",digitos[q]);
    }
    //printf("\n");

    if(digitos[a]!=-1){
        //printf("%d was used\n",a);
        init_digitos();
        return -1;
    }
    else if(digitos[b]!=-1){
        //printf("%d was used\n",b);
        init_digitos();
        return -1;
    }
    else if(digitos[c]!=-1){
        //printf("%d was used\n",c);
        init_digitos();
        return -1;
    }
    else if(digitos[d]!=-1){
        //printf("%d was used\n",d);
        init_digitos();
        return -1;
    }
    else if(digitos[e]!=-1){
        //printf("%d was used\n",e);
        init_digitos();
        return -1;
    }
    else{
        init_digitos();
        return 1;
    }
}


int main(){
    int N;
    int n_hits=0;
    vector<int> aux;
    while(scanf("%d",&N) && N!=0){
        valores_N.push_back(N);
        int limite = 98765/N;
        init_digitos();
        int fghij = 1234;
        int abcde = 0;
        while(fghij <= limite){
            abcde = fghij*N;
            if(verificacion(abcde,fghij)==1){
                //printf("%d / %d\n",abcde,fghij);
                aux.push_back(abcde);
                aux.push_back(fghij);
                fghij++;
                n_hits++;
            }
            else{
                fghij++;
            }
        }
        resultados.push_back(aux);
        if(n_hits==0){
            //printf("There are no solutions for %d.\n",N);
        }
        aux.clear();
    }




    for(int r=0;r<resultados.size();r++){
        vector<int> aux = resultados[r];
        if(aux.size()==0){
            printf("There are no solutions for %d.\n",valores_N[r]);
        }
        for(int s=0;s<aux.size();s=s+2){
            if(aux[s+1]<10000){
                printf("%d / 0%d = %d\n",aux[s],aux[s+1],valores_N[r]);
            }
            else{
                printf("%d / %d = %d\n",aux[s],aux[s+1],valores_N[r]);
            }
        }

        if(r<resultados.size()-1){
            printf("\n");
        }
    }

    return 0;
}
