#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string s1, s2;
vector<bool> v;
stack<char> s;
//funcion para ver la cantidad de combinaciones
//funciona de forma recursiva
void func (int pos1, int pos2, int posv){
	if (pos2 == s2.length()) {
		bool first = false;
		for (int i = 0; i < v.size(); i++) {
			if (first) cout << " ";
			else first = true;
			//imprime que otra combinacion es posible
			cout << (v[i]? "i": "o");
		}
		cout << endl;
	}
	//calcula la cantidad de combinaciones posibles dado el segundo string 
	//para escribir el primero de forma recursiva con la funcion func
	else {
		if (pos1 < s1.size()) {
			s.push(s1[pos1]);
			v[posv] = true;
			func(pos1+1, pos2, posv+1);
			s.pop();
		}
		if (!s.empty() && s.top() == s2[pos2]) {
			s.pop();
			v[posv] = false;
			func(pos1, pos2+1, posv+1);
			s.push(s2[pos2]);
		}
	}
}

int main() {
	//lee los dos string de entrada
	while (getline(cin, s1) && getline(cin, s2)) {
		cout << "[" << endl;
		//se los string son del mismo tamaño revisa las combinaciones
		if (s1.length() == s2.length()) {
			v.assign(2*s1.length(), false);
			func(0, 0, 0);
		}
		cout << "]" << endl;
	}
	return 0;
}