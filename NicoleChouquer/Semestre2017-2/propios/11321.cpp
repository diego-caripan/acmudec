#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class mod{
public:
  mod();
  void agregaNum(int n, int m);
  void imprimeNums();
  void imprimeNegs();
private:
  vector<int> odd;
  vector<int> oddneg;
  vector<int> even;
  vector<int> evenneg;
};

mod::mod(){

}

void mod::agregaNum(int n,int m){
  if(n%2==0){
    if(n%m >=0){
      even.push_back(n);
    } else{
      evenneg.push_back(n);
    }
    
  } else{
    if(n%m >=0){
      odd.push_back(n);
    } else{
      oddneg.push_back(n);
    }
  }
}

void mod::imprimeNums(){
  sort(even.begin(),even.end());
  sort(odd.begin(),odd.end(),greater<int>());
 
  for(int i=0; i<odd.size(); i++){
    cout << odd[i] <<endl;
  }
  for(int i=0; i<even.size();i++){
    cout << even[i] <<endl;
  }
}

void mod::imprimeNegs(){
  sort(evenneg.begin(),evenneg.end());
  sort(oddneg.begin(),oddneg.end(),greater<int>());
 
  for(int i=0; i<oddneg.size(); i++){
    cout << oddneg[i] <<endl;
  }
  for(int i=0; i<evenneg.size();i++){
    cout << evenneg[i] <<endl;
  }
}

int main(){

  vector<mod> lista;

  int nums, modulo, aux, aux2;

  for(int k=0; k<20; k++){
    cin >> nums >>modulo;

    for(int i=0; i<modulo; i++){
      lista.push_back(mod());
    }

    for(int i=0; i<nums; i++){
      cin >> aux;
      aux2 = aux%modulo;
      lista[abs(aux2)].agregaNum(aux, modulo);
    }

    cout << nums <<" " << modulo <<endl;
    for(int i=1; i<lista.size();i++){
      lista[lista.size()-i].imprimeNegs();
    }
    for(int i=0; i<lista.size();i++){
      lista[i].imprimeNums();
    }
     lista.clear();
  }
 
  cout << "0 0" << endl;
  
  return 0;
}