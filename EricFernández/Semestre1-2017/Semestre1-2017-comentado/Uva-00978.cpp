#include <iostream>
#include <vector>
#include <set>


using namespace std;
/*
Es necesario usar el multiset para tener cada ronda sin perderla una para el equipo green y otra para el equipo blue
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
	
// la batalla en caso de que azules y verdes no estan vacios
	while(!green.empty() && !blue.empty()) {
		//se almacena el estado inicial antes de la batalla
	    vector<int> gw, bw;
	    int fights = min(b, (int)min(green.size(), blue.size()));
	    //tb y tg iteradores para recorrer el set, auto es como se define la variable para que el compilador busque que es
	    for(int i=0; i<fights; i++) {
			auto tg = green.end(), 
			tb = blue.end(); 
			tg--; tb--;
		//los supervivientes 
		int gs = *tg, bs = *tb;
		green.erase(tg); blue.erase(tb);
		//si gana verde se usa este vector para almacenar el resultado
		if(gs > bs) {
		    gw.push_back(gs-bs);
		} 
		//lo mismo para el equipo azul
		else if(bs > gs) {
		    bw.push_back(bs-gs);
		}
	    }
	    // se copian los valores en el multiset
	    for(auto i : gw) green.insert(i);
	    for(auto i : bw) blue.insert(i);
	}

	//se imprimer los supervivientes en orde decreciente
	//si no quedan lemmings verdes
	if(green.empty() && !blue.empty()) {
	    cout << "blue wins\n";
	    for(multiset<int>::reverse_iterator it=blue.rbegin(); it!=blue.rend(); it++)
		cout << *it << '\n';
	} 
	//lo mismo que para los lemmings azules
	else if(!green.empty() && blue.empty()) {
	    cout << "green wins\n";
	    for(multiset<int>::reverse_iterator it=green.rbegin(); it!=green.rend(); it++)
		cout << *it << '\n';
	} else cout << "green and blue died\n";
    }
}