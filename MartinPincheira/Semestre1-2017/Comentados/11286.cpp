#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define INF 500000000
#define maxN 10000

using namespace std;

map<vector<int>, int> Count;

int main() {
// FileIn("test"); FileOut("test");
	int n;
	vector<int> v(5);

	while (scanf("%d", &n) && n) {
		
		Count.clear();
		
		while (n--) {
			//Se hace la lectura de los numeros del curso, los cuales se almacenan en un vector, para que 
			//este sea una posible combinacion de cursos a tomar, luego se ordenan y se asocian al map Count
			//en donde se tendra un contador como segundo valor para saber cuantos alumnos toman esa
			//combinacion.
			REP(i, 5) scanf("%d", &v[i]);
			sort(all(v));
			Count[v]++;
		}

		map<vector<int>, int>::iterator it = Count.begin();
		int res = 0, Max = 0;

		while (it != Count.end()) {
			//Por medio de un iterador se accede al segundo valor de Count el cual tiene el contador de
			//cuantos estudiantes toman esa combinacion a la que esta asociada.
			if (it->second == Max) res += it->second;
			else if (it->second > Max) {
				Max = it->second;
				res = it->second;
			}
			it++;
		}

		printf("%d\n", res);
	}
	
	return 0;
}
