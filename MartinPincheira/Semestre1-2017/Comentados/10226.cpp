#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	cin.ignore();
	string sep = "";
	//Se usa un map para poder asociar a cada arbol ingresado (nombre) el numero de veces que es observado por el
	//satelite. 
	map<string, int> allCounts;

	while (T--)
	{

		int totalNumber = 0;
		allCounts.clear();
		string line;

		while (getline(cin, line) && line != "")
		{
			//Se hace la lectura correspondiente de los nombres de los arboles y se utiliza un iterador sobre
			//el map, para verificar si ese nombre ya fue ingresado, si lo es aumenta el contador que esta
			//asociado a ese nombre por el map y aumenta el numero total de arboles que han sido ingresados. 
			//En caso contrario agrega este nombre al map, y aumentando tambien el contador y el numero total
			//de arboles ingresados en uno. 
			map<string, int>::iterator iter = allCounts.find(line);
			
			if (iter == allCounts.end())
				iter = allCounts.insert(pair<string, int>(line, 0)).first;

			iter->second += 1;
			++totalNumber;
		}

		cout << sep;
		sep = "\n";

		//Se realiza la operacion de calculo de porcentaje de popularidad de cada arbol, usando tambien un
		//iterador.
		for (map<string, int>::iterator iter = allCounts.begin(); iter != allCounts.end(); ++iter)
		{
			cout << iter->first << ' ' << setprecision(4) << fixed << iter->second * 100.0 / totalNumber << '\n';
		}
	}
	return 0;
}
