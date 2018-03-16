#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main(){
	string notas[12]; 
	notas[0] = "DO";
	notas[1] = "DO#";
	notas[2] = "RE";
	notas[3] = "RE#";
	notas[4] = "MI";
	notas[5] = "FA";
	notas[6] = "FA#";
	notas[7] = "SOL";
	notas[8] = "SOL#";
	notas[9] = "LA";
	notas[10] = "LA#";
	notas[11] = "SI";

	int S;
	string N;
	//while(cin >> S >> N){
	cin >> S >> N;
		int i;
		for(i=0;i<12;i++){
			if(notas[i]==N){
				break;
			}
		}
		int aux = S;
		while(aux != 0){
			if(i==0){
				i = 11;
			}
			else{
				i--;	
			}
			aux--;
		}

		cout << notas[i] << endl;
	//}
}