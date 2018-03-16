//codigo comentado 
// Fuente : https://www.davidudelson.com/blog/2015/06/20/uva-10855-rotated-square/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll; //abreviando long long

#define maxn 1000

ll N, n;
char big[maxn][maxn], little[maxn][maxn]; //creando matrices de char
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N >> n, N||n) {      //Lee mientras N y n distintos de 0
	for(int i=0; i<N; i++)
	    for(int j=0; j<N; j++)
		cin >> big[i][j];         //llena la matriz
	for(int i=0; i<n; i++)
	    for(int j=0; j<n; j++)
		cin >> little[i][j];      //llena la matriz
	int q = 0;						//inicilializa un contador en 0
	while(true) {
	    ll c = 0;							
	    for(int i=0; i<N-n+1; i++) {			
		for(int j=0; j<N-n+1; j++) {
		    bool d = true, e = true;
		    for(int a=0; a<n; a++) {
			for(int b=0; b<n; b++) {
			    if(big[i+a][j+b] != little[a][b]) {		//revisa los elementos de la matriz grande y los compara con la pequeña
				e = false;								//si son diferentes, e es falso y se detiene el algoritmo
				break;
			    }
			}
			if(!e) {
			    d = false;
			    break;
			}
		    }
		    if(d) c++;			//si no son diferentes suma uno al contador
		}
	    }
	    cout << c;   		//imprime el contador
	    if(q==3) break;		//en el caso de haber realizado ya todas las operaciones el programa se detiene
	    cout << " ";
	    char v[maxn][maxn];				//algortimo para la rotacion
	    for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
		    v[j][n-i-1] = little[i][j];
	    for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
		    little[i][j] = v[i][j];
	    q++;
	}
	cout << "\n";
    }
	
    return 0;
}