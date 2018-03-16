#include <stack>
#include <iostream>

using namespace std;

int correct(int n){
	stack<int> salida, llegada;
	int b, x;
	bool val = true;
	b = n;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x == 0){
			cout << endl;
			return 3;
		}else{
			salida.push(x);
		}	
	}
	while(val && b!=0){
		if(llegada.empty()){
			if(salida.empty() && b==0){
				val = false;
			}else{
				llegada.push(salida.top());
				salida.pop();
			}
		}else{
			if(llegada.top() == b){
				llegada.pop();
				b--;
			}else if(salida.empty() || b==0){
				val = false;
			}else if(!salida.empty()){
				llegada.push(salida.top());
				salida.pop();
			}
		}
	}
	return val;
	}

int main(){
	int cant, op;
	cin >> cant;
	while(1){
		op = correct(cant);
		if(op == 3){
			cin >> cant;
			if (cant == 0){
				return 0;
			}
		} else {
			op ? cout << "Yes" << endl : cout << "No" << endl;
		}
	}
}