#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <cctype>

using namespace std;
const int kMaxn(207);
const string kSign("::");

/*
la idea consiste en dado una lista de palabras a ignorar, buscar en un "palabra"(oracion) mas grande, las palabras que no son ignoradas.
Se debe obtener las palabras no ignoradas y ordenar de manera alfabetica, de tal manera q se impriman, las oraciones, con la palabra en mayusucula.
se debe notar que una oracion, puede contener mas de una palabra a "no ignorar", por lo que esta oracion puede ser impresa mas de una vez

para la realizacion de este ejercicio se ocupo:
un set, ya que en ella se almacenan las palabras a ignorar. se ocupa un set, ya q es facil buscar el numero de incidencias
un map, para almacenar las oraciones, ya que en algun momento necesitare llevar a mayusculas una palabra a "no ignorar"


se debe trabajar con las oraciones en minusuculas, ya que solo se imprimiran en mayusuculas las oracioens a ordenar;
*/


int main(){
    

    set<string> ignore;
    string t;
    while(getline(cin,t) && t!=kSign)
        //inserta en el set
        ignore.insert(t);

    multimap<string,string> r;
    
    while(getline(cin,t)){

        for(int i=0;i<t.size();i++)
            //minusculas
            t[i]=tolower(t[i]);
        for(int i=0;i<t.size();i++){

            if(!isalpha(t[i]))
                continue;
            int j(i);
            
            string t2;
            
            while(j<t.size() && isalpha(t[j])) {
                t2+=t[j];
                j++;
                //cuanta la cantidad de inicidencias
}            if(!ignore.count(t2)) {

                for(int k=0;k<t2.size();k++)s 
                    t2[k]=toupper(t2[k]);
                string t3(t);
                
                t3.replace(i,t2.size(),t2);
                r.insert(make_pair(t2,t3));
            }
            i=j;
        }
    }

    for(map<string,string>::iterator i=r.begin();i!=r.end();i++)
        cout<<i->second<<endl;

    return 0;
}