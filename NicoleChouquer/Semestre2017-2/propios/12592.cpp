#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Slogan{
public:
	Slogan(string first, string second);
	string showSlogan(int n);

private:
	string part1;
	string part2;

};

Slogan::Slogan(string first, string second){

	part1 = first;
	part2 = second;
}

string Slogan::showSlogan(int n){
	string aux;
	if(n==1){
		aux = part1;
	} else{
		aux = part2;
	}

	return(aux);
}

int main(){

	int n,m;
	string aux1;
	string aux2;

	scanf("%d",&n);
	cin.ignore(1,'\n');

	std::vector<Slogan> lista;

	for(int i=0; i<n; i++){
		getline(cin,aux1);
		getline(cin,aux2);
		lista.push_back(Slogan(aux1,aux2));
		
	}

	scanf("%d",&m);
    cin.ignore(1,'\n');
    
	for(int i=0; i<m; i++){
		getline(cin,aux1);
		for(int j=0; j<n; j++){
			if(aux1 == lista[j].showSlogan(1)){
				cout << lista[j].showSlogan(2) << endl;
				break;
			}
		}
	}

	return 0;
}