#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
//define las variables y el tamaño de la matriz donde se inserta
//y una auxiliar
int n, g[3][3], gg[3][3];
int main() {
    // 
    vector< pii > sides;
    sides.push_back(make_pair(0, 1));
    sides.push_back(make_pair(0, -1));
    sides.push_back(make_pair(1, 0));
    sides.push_back(make_pair(-1, 0));

    //lee la entrada
    scanf("%d", &n);
    while(n--) {
	for(int i=0; i<3; i++) {
	    for(int j=0; j<3; j++) {
		char c = '\n';
		while(c == '\n') scanf("%c", &c);
		g[i][j] = c-'0';
	    }
	}
	int k = 0;
	while(true) {
		//para salir del while
	    bool all_zeros = true;
	    for(int i=0; i<3; i++) 
		for(int j=0; j<3; j++)
		    if(g[i][j] != 0) all_zeros = false;
		//aqui sale del while
	    if(all_zeros) break;
	    k++;
	    for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
		    gg[i][j] = 0;
		    for(auto p : sides) {
		    //modifica la matriz auxiliar
			if(0 <= j+p.first && j+p.first < 3 &&
			   0 <= i+p.second && i+p.second < 3) {
			    gg[i][j] ^= g[i+p.second][j+p.first];
			}
		    }
		}
	    }
	    //traspasa los datos de la matriz auxuliar a la original
	    for(int i=0; i<3; i++) 
		for(int j=0; j<3; j++) 
		    g[i][j] = gg[i][j];
	}
	// imprime g para cada posible entrada
	printf("%d\n", k-1);
    }
	
    return 0;
}