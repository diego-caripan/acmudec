#include <iostream>
#include <string>

using namespace std;

int main(){
	int numb, aux;
	while(cin >> numb){
		if(numb == 0)
			break;
		aux = 0;
		while(1){
			while(numb !=0){
				aux = aux + numb%10;
				numb = numb/10;
			}
			if(aux/10 == 0)
				break;
			else{
				numb = aux;
				aux = 0;
			}
		}
		cout << aux << endl;
	}
}