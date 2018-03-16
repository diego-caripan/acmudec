#include <iostream>

using namespace std;


int main() {

	double h,u,d,f;
	int contador;
	bool flag;
	double recorrido;

	while(1){

	cin >> h >> u >> d >> f;

		if( h == 0 )
			break;

		double baja=(u*(f/100.0));
		recorrido= 0,contador=1;
		flag= false;
	
		while(1){
			
			if(u>0) recorrido+=u;

			if(recorrido > h){
				flag = true;
				break;
			}

			recorrido -=d;
			u -=baja;

			if (recorrido < 0){
				break;
			}
			contador++;
		}		

		if(flag)
			cout << "success on day " << contador << "\n";
		else 
			cout << "failure on day " << contador << "\n";
	}

}