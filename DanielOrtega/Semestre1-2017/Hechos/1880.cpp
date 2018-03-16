
#include <iostream>

using namespace std;


int main(){
	
	int n[3],k;
	int array[3][4000];

	for (int i =0; i < 3;i++){
		cin >> n[i];

		for(int j = 0; j< n[i];j++){
			cin >> array[i][j];
	}

}

int buscar,coin,contador;

for(int t = 0 ; t < n[0] ; t++){

	buscar = array[0][t];
	coin =0;

for (int k = 1; k< 3; k++){
	for(int w = 0; w < n[k];w++){



	if (buscar == array[k][w])
		coin++;

	}
}

if (coin == 2) contador++;


}

cout << contador;





 return 0;
}
