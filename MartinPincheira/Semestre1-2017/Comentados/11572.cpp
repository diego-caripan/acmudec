#include <iostream>
#include <map>

using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
	
	int cases, n;
	int snowflake;
	int *snowflakes = new int[1000001];
	int first, current, result, counter;
	cin >> cases;
	
	while (cases--) {
		first = current = result = counter = 0;
		//Se utiliza un map para asociar el snowflake obtenido con un valor de verdad, el cual nos indicará si fue
		//procesado por la maquina.
		map<int,bool> taken;
		cin >> n;

		while (n--) {
			cin >> snowflake;
			snowflakes[current++] = snowflake;

			if (taken.find(snowflake) != taken.end()) {
			//Se encuentra que el snowflake ya se encuentra en el map taken, esto quiere decir que ya fue
			//procesado, por lo que se elimina, y se disminuye el contador.
				if (counter > result) result = counter;

				while (true) {
					if (snowflakes[first] == snowflake) break;
					taken.erase(snowflakes[first]);
					counter--;
					first++;
				}

				first++;
			} else {
				//Se aumenta el contador por cada snowflake distinto procesado, y almacena el valor de 
				//este en el map asociandole un valor verdadero.
				counter++;
				cout << snowflake << endl;
				taken[snowflake] = true;
			}
		}

		if (counter > result) result = counter;

		cout << result << endl;
	}

	delete snowflakes;
	return 0;
}
