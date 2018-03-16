#include <bits/stdc++.h>
using namespace std;

int main(){
	char x;
	string line;
	long int N,K,M,i,y,j,a;
	double total;
	vector<int> valor;
	vector<char> letra;
	cin >> N;
	for(a=0 ; a<N ; a++){
		cin >> K;
		for(i=0 ; i<K ; i++){
			cin >> x;
			letra.push_back(x);
			cin >> y;
			valor.push_back(y);
			//cout << "x: " << x << " y: " << y << endl;
		}
		cin >> M;
		total = 0;
		for(int k=0 ; k<=M ; k++){
			getline(cin,line);
			for(i=0 ; i<line.length() ; i++){
				x = line[i];
				for(j=0 ; j<valor.size() ; j++){
					if(x == letra[j]){
						total += valor[j];
						//cout << letra[j] << " " << valor[j] << " " << total << endl;
						break;
					}
				}
			}
			line.clear();
		}
		total = total/100;
		printf("%0.2lf$\n",total);
		//cout << total/100 << "$" << endl;
		valor.clear();
		letra.clear();
	}
	return 0;
}