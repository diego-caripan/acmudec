#include <bits/stdc++.h>
using namespace std;

int main(){
	string line;
	while(getline(cin,line)){
		double sum = 0;
		if(line[0]== '_') continue;
		for(int i=0; i<line.size(); i++){
			if(line[i] == 'o'){
				(i > 6)?sum+=pow(2,line.size() - i-2):sum+=pow(2,line.size()- i-3);
			}
		}
		cout << (char)sum;
	}
	return 0;
}