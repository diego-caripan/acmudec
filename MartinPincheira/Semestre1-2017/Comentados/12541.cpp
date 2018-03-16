#include <stdio.h>
#include <iostream>

/*Lo que realiza este algoritmo es invertir la fecha de nacimiento y representarla como una suma de digitos, dejando asi representado el numero como yyyymmdd, eso por medio de dd+mm*100+yy*10000, lo cual permite comparar si las las fechas son mayores o menores.*/

using namespace std;

int main(){

	int n;

	while(scanf("%d", &n) == 1){

		int old = 0, young = 2147483647;
		string oa, ya, name;
		int dd, mm, yy;
		
		while(n--){
			cin >> name >> dd >> mm >> yy;
			dd = dd+mm*100+yy*10000;
	
			if(dd > old) old = dd, oa = name;
			if(dd < young) young = dd, ya = name;
		}
	
		cout << oa << endl;
		cout << ya << endl;
	}

	return 0;
}
