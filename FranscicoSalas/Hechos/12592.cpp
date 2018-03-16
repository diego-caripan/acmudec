#include <iostream>
#include <string>

using namespace std;

int main(){

	int slogans, Q;
	cin >> slogans;
	string str1[200], str2[200], strAux, temp;
	getline(cin,temp);
	for(int i = 0; i < slogans; i++){
		getline(cin, str1[i]);
		getline(cin, str2[i]);
		//cout << str1[i] << endl;
		//cout << str2[i] << endl;
	}

	cin >> Q;
	getline(cin,temp);
	//cout << Q << endl;
	for(int i = 0; i < Q; i++){
		//strAux.clear();
		getline(cin, strAux);
		//cout << strAux << endl;
		for(int i = 0; i < slogans; i++){
			if(strAux == str1[i]){
				cout << str2[i] << endl;
				break;
			}
		}
	}

}