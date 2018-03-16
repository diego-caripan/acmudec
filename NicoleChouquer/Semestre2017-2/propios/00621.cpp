#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){

  int n;
  string s;

  scanf("%d",&n);
  cin.ignore(1,'\n');

  for(int i=0; i<n; i++){

    getline(cin,s);

    if(s.length()<3){

      if(s=="1" || s == "4" || s== "78"){
        cout << "+" << endl;
      } else {
        cout << "-" << endl;
      }

    } else{

      if(s[s.length()-1]=='5'&& s[s.length()-2]=='3'){
        cout << "-" << endl;
      }
      else if(s[0]=='9' && s[s.length()-1]== '4'){
        cout << "*" << endl;
      } else {
        cout << "?" <<endl;
      }

    }

  }

  return 0;
}