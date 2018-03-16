#include <iostream>
#include <cstdio>
#include <map>

using namespace std;



/*
El problema consiste en obtener el porcentaje de cada arbol con respecto al total del numero total de arboles

  el problema es resuelto con un map, ya que, se toma como identificador el nombre del arbol, y cada vez que este aparezca se aumenta en 1,
  el numero de apariciones,
  ademas se tiene un contador: total que cuenta la cantidad de arboles ingresados
  para obtener las estadisticas con ellas

*/



int main(){

  int numTestcase;
  while( scanf("%d", &numTestcase) != EOF ){
    getchar(); // for '\n'

    string input;

    getline(cin, input); // for blank line

    for( int testcase = 0 ; testcase < numTestcase ; ++testcase ){
      if( testcase > 0 ){
        printf("\n");
      }

      map<string, int> numSpecies;

      int total = 0;
        // mientras exist
      while( getline(cin, input) && input != "" ){
        ++numSpecies[input];
        ++total;
      }

      /* aqui se imprimen los  nombres de los arboles en orden alfabetico, donde se muestran los 
      porcentajes de aparicion con respecto al total del input ingresado, con su porcentaje respectivo
      
*/
      for( map<string, int>::iterator it = numSpecies.begin();
           it != numSpecies.end() ; ++it ){
        printf("%s %.4f\n", it->first.c_str(), (double)it->second / total * 100);
      }

    }

  }
  return 0;
}