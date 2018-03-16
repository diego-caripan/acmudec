#include <iostream>
#include <stdio.h>
#include <istream>


using namespace std;

int matriz[3][3];

void funcionf() {
	int prima[3][3];

	prima[0][0] = (matriz[0][1] + matriz[1][0]) % 2;
	prima[0][1] = (matriz[0][0] + matriz[1][1] + matriz[0][2]) % 2;
	prima[0][2] = (matriz[0][1] + matriz[1][2]) % 2;
	prima[1][0] = (matriz[0][0] + matriz[1][1] + matriz[2][0]) % 2;
	prima[1][1] = (matriz[0][1] + matriz[1][0] + matriz[1][2] + matriz[2][1]) % 2;
	prima[1][2] = (matriz[1][1] + matriz[0][2] + matriz[2][2]) % 2;
	prima[2][0] = (matriz[2][1] + matriz[1][0]) % 2;
	prima[2][1] = (matriz[2][0] + matriz[1][1] + matriz[2][2]) % 2;
	prima[2][2] = (matriz[2][1] + matriz[1][2]) % 2;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriz[i][j] = prima[i][j];
		}
	}
}


int main() {

	cout << "holi";
	int casos;

	
	scanf("%d",&casos);
	while (casos--) {

		for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
			 		scanf("%1d", &matriz[i][j]);
			}
		}
		cout << "holi";
				

	
		int intentos = -1;
		int bandera = 1;

		while (1) {

			funcionf();
			intentos++;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {				
					if (matriz[i][j] > 0)
						bandera=0;
					break;
				}
			}

			if(bandera) break;
		}

		cout << intentos << endl;

	}

	return 0;
}