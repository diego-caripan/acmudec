#include <iostream>
#include <cstdio>

using namespace std;

int main(){

	int duracion, ndepreciacion, nummes;
	double pagoinicial, cantidadpres,porcentajedep, aux, val, temp, cuota;
	

	while(scanf("%d %lf %lf %d", &duracion, &pagoinicial, &cantidadpres, &ndepreciacion) && duracion >= 0){
		
		val = cantidadpres;
		temp = pagoinicial + cantidadpres;
		cuota = cantidadpres/duracion;
			
		double deprec[1000] = {};

		while(ndepreciacion>0){

			cin >> nummes;
			cin >> deprec[nummes];
			ndepreciacion--;
		}

		int i=0;
		while(i <= duracion){
	
			if(deprec[i] == false){
				deprec[i] = deprec[i-1];
			}
			
			aux = 1 - deprec[i];
			temp = temp*aux;

			if(val <= temp){
	
				cout << i << " month";
				
				if(i != 1){
					cout << "s";
				}
				cout << "\n";
				break;
			}
				
			val = val - cuota;			
			i++;
		}
	
	}	

	return 0;
}
