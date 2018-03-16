#include <bits/stdc++.h>

using namespace std;

char tranf(char c){
  if(c < 91) c += 32;
  return c;

}

int main(){
  string s;
  while(1){
    getline(cin, s);
    if(s[0] == '*')break;
    vector <char> comparar;
    for(int i = 0; i < s.size();i++){
      if(i == 0)comparar.push_back(tranf(s[i]));
      else if(s[i] == ' ')comparar.push_back(tranf(s[i+1]));
    }
    char c = comparar[0];
    bool estado = true;
    for(int i = 0; i < comparar.size() ; i++){
      if(comparar[i] != c)estado=false;
    }
    if(estado)puts("Y");
    else puts("N");
  }
  return 0;
}
