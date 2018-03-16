#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char s[1000001];


/*
El problema consiste en que dado una secuencia encontrar el substring que se repite la mayor cantidad de veces


el problema se resuelve con un map
*/

int main(){

    int N;
    map<long long, int> cont;
    
    while(scanf("%d %s",&N,s) == 2){

        int L = strlen(s);
        cont.clear();
        
        for(int i = 0;i + N <= L;++i){
            long long aux = 0;
            
            for(int j = 0;j < N;++j)
                aux = aux*26 + (s[i+j]-'a');
            //s[i+j] hace que se pueda ir evaluando donde -'a', lo que va asignado valores desde 0 a 25
        /*   j  0 1 2 3 4 5 6 7 8  9
            i=0 0 1 2 3 4 5 6 7 8  9 
            i=1 1 2 3 4 5 6 7 8 9  10
            i=2 2 3 4 5 6 7 8 9 10 11    
            */

            //aux se multiplica por 26 para mostrar que se hace un cambio de posicion, es como unidad -> decimal..
            // asi pone un 1 en la posicion que deberia verificar
            cont[aux]++;
        }
        


        long long ans_hash;
        int best = -1;

        // va comparadno por los valores obtenidos en el paso anterior, por los valores de aux.
        // hasta obtener el mayor
        //ans_hash almacena el mayor valor
        
        for(map<long long, int> :: iterator it = cont.begin();it != cont.end();it++){
            if(it->second > best){
                ans_hash = it->first;
                best = it->second;
            }
        }
        
        string ans;
        
        // en esta parte el numero mayor, se vuelve va desaciendo, para poder obtener la combinacion de string mas repetidas,
        //asi por cada iteracion realizada en el ciclo se va imprimiendo una letra que corresponde a letras en la subsecuencia mas grande
        for(int i = 0;i < N;++i){
            ans = (char)(ans_hash % 26 + 'a') + ans;
            ans_hash /= 26;
        }
        
        puts(ans.c_str());
    }
    
    return 0;
}