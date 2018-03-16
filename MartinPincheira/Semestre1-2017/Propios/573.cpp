#include <iostream>
#include <cstdio>

//H: altura del pozo
//U: distacia que puede subir
//D: distancia que se desliza
//F: factor de fatiga

using namespace std;

int main(){

	double H, U, D, F;
	int dia;
	double IH, temp, factor;	

	while(cin >> H && H != 0){

		cin >> U;
		cin >> D;
		cin >> F;

		IH = 0;		
		factor = U*(F/100.0);
		temp = U;

		dia = 1;
		while(1){
		
			IH = IH + temp;
			
			if(IH > H){
				cout << "success on day " << dia << endl;
				break;
			}
			IH = IH - D;

			if(IH < 0){
				cout << "failure on day " << dia << endl;
				break;
			}
			temp = temp - factor;
	
			if(temp < 0){ 
				temp = 0;	
			}
			dia++;
		}	

	}
	
	return 0;
}
