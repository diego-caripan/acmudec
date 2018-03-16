#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
El problemilla consiste en a cada letra y cada secuencia de letras asignararle un cierto valor
*/
map<string, int> M;
/*
Aqui ocurre la magia
Usa el map para guardar el valor de la letra o letras
y una cola para ir viendo en que cual va, el chiste es que
cuando termina con una palabra, la pushea a la cola junto con la que sigue
asi, va generando palabras en orden, cuando tiene una de longitud 5
termina la funcion.
*/
void generate_positions(){
    queue<string> Q;
    for(char c='a';c<='z';c++) Q.push(string(1,c));
    
    string s;
    
    int cont=1;    
    
    while(!Q.empty()){
        s=Q.front();
        Q.pop();
        
        M[s]=cont;
        cont++;
        
        if(s.size()==5) continue;
        
        for(char c=s[s.size()-1]+1;c<='z';c++) Q.push(s+c);
    }
}

int main(){
    generate_positions();
    /*
    Como es un mapa si no se encuentra un elemento el iterador apunta a una posicion
    luego del final del mapa, donde el valor de la clave es 0
    */
    string s;
    map<string, int> :: iterator it;
    
    while(cin>>s){
        it=M.find(s);
        if(it==M.end()) cout<<0<<endl;
        else cout<<it->second<<endl;
    }
    
    return 0;
}