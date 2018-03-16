
#include <iostream>
#include <vector>
using namespace std;

int main(){
	
int loanDur, nRec; // numero de cuotas y numero de despreciaciones
	double downPayment, loan, decP[101]; // el pago unicial, el prestamo, y el vector para guardar

	while (true) { // para que siempre este funcionando
		cin >> loanDur >> downPayment >> loan >> nRec; // escanear
		if (loanDur < 0) // para salir del while por la condicion del enunciado 
			break;

		int m; // numero del mes
		double p; // porcentaje de despreciacion
		while (nRec--) { // hasta que se acaben las despresiaciones
			cin >> m >> p;	// se escanean
			for (int i = m; i < 101; i++) // hubica el mes y la despreciacion
				decP[i] = p;              // como va creciando y la despreciacion cambia entonces lo llena
		}                                 

		int now = 0;    // el numero de meses para que sea menor
		double monthlyPayment = loan / loanDur; // lo que se paga al mes
		double curVal = (loan + downPayment) * (1 - decP[0]); // el prestamo + lo que pago - la despreciacion en el primer mes
		double curLoan = loan; // el prestamo
		while (curVal < curLoan) { // cuando sea menor quiere decir que ya se equiparo
			now++;
			curLoan -= monthlyPayment;
			curVal = curVal * (1-decP[now]);
		}

		cout << now << " month"; // solo para agregar la 's' a los meses
		if (now != 1)
			cout << "s";
		cout << endl;
	}

	return 0;
}