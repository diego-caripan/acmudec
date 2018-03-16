#include <iostream>
#include <vector>
#include <set>


using namespace std;



/*
EL problema es resuelto usando la estructura de datos multiset, en el se pueden almacenar distintas copias que tengan el mismo valor.
Es importante almacenar el estado del principio de cada ronda hasta el final de dicha ronda.
gw green vector
bw blue vector

*/


int t, b, ng, nb;

multiset<int> green, blue;

int main() {

    cin >> t;

    for(int tt=0; tt<t; tt++) {

/*
b numero de campo de batallas
ng numero de lemmings verdes
nb numero de lemmings  blue
*/
	if(tt > 0) cout << '\n';
		green.clear();
		blue.clear();
		cin >> b >> ng >> nb;
	
	// lee los lemmings verdes
	for(int i=0; i<ng; i++) {
	    int x;
	    cin >> x;
	    green.insert(x);
	}
	// lee los lemmings azules
	for(int i=0; i<nb; i++) {
	    int x;
	    cin >> x;
	    blue.insert(x);
	}
	
// caso en que quedan lemmings verdes y azules para resolver, por lo que se producira una "batalla"
	while(!green.empty() && !blue.empty()) {
		// vector que almacena la el estado incial del campo de batalla, para los lemmings azules y los lemmings verdes
	    vector<int> gw, bw;


	    int fights = min(b, (int)min(green.size(), blue.size()));
	    	// la variable auto, le dice al compilador que adivine el tipo de dato que se le etregara, por lo que tg,tb es un int
	    //tb es un iterador hasta el final del blue
	    //tg es un iterador hasta el final del green
	    for(int i=0; i<fights; i++) {
			auto tg = green.end(), 
			tb = blue.end(); 
			tg--; tb--;
		//gs green survivors
		//bs blue survivors
		int gs = *tg, bs = *tb;
		green.erase(tg); blue.erase(tb);
		// se almacenan los estados de las batallas en el vector, si gana verde
		if(gs > bs) {
		    gw.push_back(gs-bs);
		} 
		// se almacenan los estados de las batallas en el vector, si gana azul
		else if(bs > gs) {
		    bw.push_back(bs-gs);
		}
	    }
	    	// se copian los valores nuevamente en el multiset
	    for(auto i : gw) green.insert(i);
	    for(auto i : bw) blue.insert(i);
	}

// caso en que solo quedan lemmings azules
// por lo que se imprimem, los valores de lemmings para las rondas, en las que ya no quedan lemmmings verdes
// se imprimen los lemmings sobrevivientes en orden decreciente
	if(green.empty() && !blue.empty()) {
	    cout << "blue wins\n";
	    for(multiset<int>::reverse_iterator it=blue.rbegin(); it!=blue.rend(); it++)
		cout << *it << '\n';
	} 
// caso en que quedan lemmings azules
// por lo que se imprimen, los valores de lemmings para las rondas, en las que ya no quedan lemmmings verdes
// se imprimen los lemmings sobrevivientes en orden decreciente
	else if(!green.empty() && blue.empty()) {
	    cout << "green wins\n";
	    for(multiset<int>::reverse_iterator it=green.rbegin(); it!=green.rend(); it++)
		cout << *it << '\n';
	} else cout << "green and blue died\n";
    }
}