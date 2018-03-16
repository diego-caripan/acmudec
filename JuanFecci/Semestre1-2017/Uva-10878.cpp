#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)

void D(int x, string fin="\n"){
	cout << x << fin;
}

int main(){

	int letint, ind;
	string aux1, aux2;
	getline(cin, aux1);
	getline(cin, aux2);

	while(aux1.compare(aux2) != 0){
		letint = 0;
		ind = 9;
		for(int i=1; i< 128; i*=2){
			if (aux2[ind] == 'o') letint+=i;
			ind-=1;
			if(ind == 6) ind = 5;
		}
		printf("%c",(char)letint );
		getline(cin, aux2);
	}


}