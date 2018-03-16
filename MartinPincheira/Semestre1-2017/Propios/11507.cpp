#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

string Mov(string a, string b){

	string aux;
	
	if(a == "+x" && b == "+y"){
		aux = "+y";
		return aux;
	}
	if(a == "+x" && b == "-y"){
		aux = "-y";
		return aux;
	}
	if(a == "+x" && b == "+z"){
		aux = "+z";
		return aux;
	}
	if(a == "+x" && b == "-z"){
		aux = "-z";
		return aux;
	}

	if(a == "-x" && b == "+y"){
		aux = "-y";
		return aux;
	}
	if(a == "-x" && b == "-y"){
		aux = "+y";
		return aux;
	}
	if(a == "-x" && b == "+z"){
		aux = "-z";
		return aux;
	}
	if(a == "-x" && b == "-z"){
		aux = "+z";
		return aux;
	}

	if(a == "+y" && b == "+y"){
		aux = "-x";
		return aux;
	}
	if(a == "+y" && b == "-y"){
		aux = "+x";
		return aux;
	}
	if(a == "+y" && b == "+z"){
		aux = "+y";
		return aux;
	}
	if(a == "+y" && b == "-z"){
		aux = "+y";
		return aux;
	}

	if(a == "-y" && b == "+y"){
		aux = "+x";
		return aux;
	}
	if(a == "-y" && b == "-y"){
		aux = "-x";
		return aux;
	}
	if(a == "-y" && b == "+z"){
		aux = "-y";
		return aux;
	}
	if(a == "-y" && b == "-z"){
		aux = "-y";
		return aux;
	}

	if(a == "+z" && b == "+y"){
		aux = "+z";
		return aux;
	}
	if(a == "+z" && b == "-y"){
		aux = "+z";
		return aux;
	}
	if(a == "+z" && b == "+z"){
		aux = "-x";
		return aux;
	}
	if(a == "+z" && b == "-z"){
		aux = "+x";
		return aux;
	}

	if(a == "-z" && b == "+y"){
		aux = "-z";
		return aux;
	}
	if(a == "-z" && b == "-y"){
		aux = "-z";
		return aux;
	}
	if(a == "-z" && b == "+z"){
		aux = "+x";
		return aux;
	}
	if(a == "-z" && b == "-z"){
		aux = "-x";
		return aux;
	}

}

int main(){

	int L, i;
	string dec;
	string cable;

	while(cin>>L && L!=0){

		cable = "+x";

		for(i=1; i<L; i++){

			cin >> dec;
			
			if(dec != "No"){
				cable = Mov(cable,dec);
			}

		}
		
		cout << cable << endl;
	}
	
	return 0;
}
