#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int N;
	int aux = 0;
	cin >> N;
	int montes[N];
	int creciente = 0 ;int decreciente = 0;
	int n_montes= 0;

	for(int i=0;i<N;i++){
		cin >> montes[i];
	
		if (creciente == 0 && aux < montes[i]){
			creciente = 1;
		}

		else if(creciente == 1 && aux > montes[i]){
			decreciente = 1;
		}

		

		if(creciente == 1 && decreciente == 1) {
			creciente = 0;
			decreciente = 0;
			n_montes += 1;
		}
		else if(creciente == 1 && i == (N-1)) {
				n_montes +=1;
		}

		aux = montes[i];

	}


	printf("%d\n",n_montes);

	return 0;
}
