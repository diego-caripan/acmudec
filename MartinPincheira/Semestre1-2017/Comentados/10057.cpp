#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)//Definida para el iterador for
#define fr1(a, n) for(a = 1; a <= n; a++)
#define frR(a, n) for (a = n; a >= 0; a--)
#define sc(a) scanf("%d", &a) //Definida para escanear el input
#define pr(a) printf("%d\n", a)
#define p(i, j) make_pair(i, j)
#define fi first
#define se second
#define pb push_back
#define clr(a) memset(a, 0, sizeof a);

const int oo = 0x3f3f3f3f;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){

	vi v;
	int n, i;

	while(sc(n) > 0){
		
		//Se recalcula el tamaño del vector vi, y se almacenan en el los valores correspondientes ingresados.
		v.resize(n);
		fr(i,n) sc(v[i]);
		//Luego los elementos del vector se ordenan para poder averiguar cual es el valor correspondiente y
		//cuantos satisfacen la propiedad.
		sort(v.begin(), v.end() );

		//Para obtener el menor valor solo basta acceder a v[(n-1)/2] dado que v se encuentra ordenado, luego para 
		//averiguar cuantos valores cumplen la propiedad se utiliza upper_bound y lower_bound, lo cuales se restan
		//dado que se obtienen de ellos la posicion de los elementos que lo cumplen, y asi entrega la cantidad de
		//elementos que satisfacen la propiedad. Por ultimo se entrega el numero de posibles enteros diferentes, esto
		//haciendo la diferencia del elemento ubicado en la mitad del arreglo y el antecesor, y sumar 1 a esto para 
		//poder obtenerlo.
		printf("%d %d %d\n", v[(n-1)/2], (int)(upper_bound(v.begin(), v.end(), v[n/2]) - lower_bound(v.begin(), v.end(), v[(n-1)/2])), v[n/2]-v[(n-1)/2]+1);

	}
	
	return 0;
}
