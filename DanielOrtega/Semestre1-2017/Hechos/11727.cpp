#include <iostream>

using namespace std;


int main() {

	int casos=1,menor,medio;
	int n,numero[4];
	int max,min,pos;

	cin >> n;

while(n--){

		for(int i = 0; i < 3; i++){
			cin >> numero[i];
		}

		max = numero[0];
		menor = numero[0];

		for(int j=0; j < 3;j++){
			if (max < numero[j] )
				max =numero[j];
				 pos = j;
		}


	int c=0;
		for (int w =0; w < 3; w++){
			
			if(numero[c]< menor)	
				menor= numero[c];

			c++;
		}

	


		for(int t = 0; t< 3; t++){
			if(menor == numero[t]) continue;
			else if (max == numero[t]) continue;

			medio = numero[t];
		}

			cout << "Case " << casos++ <<": " << medio<< "\n";

	}


	}


