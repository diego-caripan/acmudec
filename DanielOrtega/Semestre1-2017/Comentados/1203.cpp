#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
El problema consiste en que dado un numero de registro ver la cantidad de periodos en los que se repite...
es decir, generar un especie de linea de tiempo, donde, se muestren periodicamente valores, donde en cada periodo, yy por aparacion  se valla
multiplicando el numero para el caso de prueba dado se tiene:

* marca el que se escoge en esa iteracion
linea de tiempo

2005     300     600    
		  *	      *(2)
2004  200   400  600  
		*    *    *(1)

(1) y (2), se colocan ya que si ambos poseen el mismo periodo, se debe imprimir, por q_num, pero en orden ascendete

num: corresponde al año del registo
period: corresponde al periodo del registro
repeatingperiod: corresponde al numero de repetciones de periodos
*/
struct Node {
	int num;
	int period;
	int repeatingPeriod;
	// contructor periodo con los datos
	Node(int _num, int _period, int _repeatingPeriod) {
		num = _num; period = _period; repeatingPeriod = _repeatingPeriod;
	}
	// constructor vacio
	Node() {
		num = 0; period = 0; repeatingPeriod = 0;
	}
		// corresponde al operador comparacion, donde si los periodos son iguales, se retotnar el mas num mas pequeño
	bool operator() (const Node& lhs, const Node& rhs) {
		if (lhs.repeatingPeriod == rhs.repeatingPeriod) {
			return lhs.num > rhs.num;
		}
		return lhs.repeatingPeriod > rhs.repeatingPeriod;
	}
};

/*
el problema es resuelto con una cola de prioridad, ya que esta siempre se ordenadara, de acuerdo a la funcion definida en node*/

int main() {

	priority_queue<Node, vector<Node>, Node> pq;

	string temp;

	int num, period;
	// lee el parametro register hasta encontrar el #
	while ((cin >> temp) && (temp != "#")) {
		// lee el numero y el periodo
		cin >> num >> period;
			// inserta el nodo generado, en la cola de priodad
		pq.push (Node(num,period,period));
	}

	int q; cin >> q;
		//q corresponde a la cantidad e periodos q se realizan
	for(int i=0;i<q;i++){
			// num, corresponde a al num, q esta primero, en la cola, y como estara ordenado, se puede asegurar q siempre sera el
		//menor
		int num = pq.top().num;
		int period = pq.top().period;
		// se aumenta en el valor period el valor seleccionado
		int repeatingPeriod = pq.top().repeatingPeriod + period;
		// se elimina para luego, volver a ser insertado, pero con el nuevo valor de periodo
		pq.pop();
		cout << num << endl;
		// se vuelve a insertar con el nuevo perido
		pq.push(Node(num,period,repeatingPeriod));
	}
	return 0;
}