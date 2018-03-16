#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iterator>

using namespace std;

int main(){

  int t, n, aux;
  vector<int> tiendas;
  vector<int> distancias;

  cin >> t;

  for(int i=0; i<t; i++){
    cin >> n;
    for(int j=0; j<n; j++){
      cin >> aux;
        tiendas.push_back(aux);
    }
    
    sort(tiendas.begin(),tiendas.end());

    for(int j=*min_element(tiendas.begin(),tiendas.end()); j<=*max_element(tiendas.begin(),tiendas.end()); j++){
      aux = 0;
      for(int k=0; k<tiendas.size();k++){
        
          if(k==0){
            aux+= abs(tiendas[k]-j);
          }
          else{
            aux+= abs(tiendas[k]-tiendas[k-1]);
           
          }
        
      }
      aux+= abs(tiendas[tiendas.size()-1]-j);
      distancias.push_back(aux);
      aux = 0;
    }

    cout << *min_element(distancias.begin(),distancias.end()) <<endl;
   
    tiendas.clear();
    distancias.clear();

  }

  return 0;
}