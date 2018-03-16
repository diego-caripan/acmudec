#include <iostream>
#include <set>

using namespace std;

int main()
{
	int numDays;
	while (cin >> numDays, numDays)
	{
		//Se utiliza un multiset porque los elemetos se ordenan segun su valor, lo cual es util para resolver
		//este problema.

		multiset<int> numbers;

		long long cost = 0;
		//Se itera sobre el numero de casos (dias).
		while (numDays--)
		{		
			int k;
			cin >> k;
			//Se itera sobre el numero de compras, y se inserta el valor de las compras en el multiset.
			while (k--)
			{
				int t;
				cin >> t;
				numbers.insert(t);
			}
		
			//se definen los iteradores sobre el multiset para obtener el valor mas alto y mas bajo de este.
			multiset<int>::iterator lowest = numbers.begin();
			multiset<int>::iterator highest = --numbers.end();
			
			//Se calcula el total pagado a los clientes, realizando la diferencia entre el valor mas bajo y 
			//mas alto, y luego se eliminan del multiset.
			cost += *highest - *lowest;
			numbers.erase(lowest); numbers.erase(highest);
		}

		cout << cost << '\n';
	}
	
	return 0;
}
