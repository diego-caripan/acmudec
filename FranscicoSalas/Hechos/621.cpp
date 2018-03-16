#include <iostream>

using namespace std;

int main(){

	int cases;
	int largo = 0;
	string S;

	cin >> cases;
	while(cases--){
		cin >> S;
		largo = S.length();
		if(S == "1" || S == "4" || S == "78")
			cout << '+' << endl;
		else if(S[largo-2] == '3' && S[largo-1] == '5' && largo > 2)
			cout << '-' << endl;
		else if(S[0] == '9' && S[largo-1] == '4' && largo > 2)
			cout << '*' << endl;
		else if(S[0] == '1' && S[1] == '9' && S[2] == '0' && largo > 3)
			cout << '?' << endl;
		else
			cout << '?' << endl;
	}
}
