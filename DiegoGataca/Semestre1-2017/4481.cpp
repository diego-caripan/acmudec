#include <bits/stdc++.h>

using namespace std;

int main(){
  while(1){
    string s;
    cin >> s;
    if(s.size() == 1)break;
    bool inicio = false;
    int sol = 0;
    double acum = 0.0;
    char c;
    for(int i = 0; i < s.size();i++){
      c = s[i];
      if(c == '/'){
	if(!inicio)inicio = true;
	else if(inicio){
	  if(acum == 1.0)sol++;
	  acum = 0.0;
	}
      }
      else {
	if(c == 'W')acum+=1.0;
	if(c == 'H')acum+=1.0/2.0;
	if(c == 'Q')acum+=1.0/4.0;
	if(c == 'E')acum+=1.0/8.0;
	if(c == 'S')acum+=1.0/16.0;
	if(c == 'T')acum+=1.0/32.0;
	if(c == 'X')acum+=1.0/64.0;
      }
    }
    printf("%d\n",sol);
  }
  return 0;
}
